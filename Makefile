# -----------------------------------------------------------------------------
# 
#                              M A K E F I L E
# 
# zum Uebungsbetriebssystem OOStuBS der Lehrveranstaltung 'Betriebssystembau'.
# -----------------------------------------------------------------------------
#
# Durch Eingabe von 'make' werden die Quelltexte des Systems kompiliert. 'make
# bootdisk' schreibt das System-Image auf einen USB-Stick, von dem das System
# dann gebootet werden kann. Mit 'make clean' wird im Verzeichnis aufgeraeumt.
# Die Targets 'qemu', 'qemu-gdb', 'gdb', 'ddd' starten den QEMU-Emulator mit
# bzw. ohne GDB-Stub und starten den GDB- bzw. den DDD-Debugger, um sich dann
# mit dem GDB-Stub zu verbinden. Auf Poolrechnern koennen mit 'vorgabe2' bis
# 'vorgabe7' die Vorgaben fuer eine neue Aufgabe in das aktuelle
# Arbeitsverzeichnis eingepflegt werden.
#
# -----------------------------------------------------------------------------

# -----------------------------------------------------------------------------
# Liste der Quelltexte:

STARTUP_SOURCE = ./startup.asm
CC_SOURCES = $(shell find . -name "*.cc")
C_SOURCES = $(shell find . -name "*.c")
ASM_SOURCES = $(shell find ./machine -name "*.asm")

# Einstellungen in Abhaengigkeit vom Generierungssystem:
#
#    ASMOBJFORMAT: Ausgabeformat fuer den Assembler. Das Format muss dem
#                  jeweiligen Format des verwendeten C++ Compilers angepasst
#                  werde, damit gemischte Objektdateien gelinkt werden koennen.
#    OBJDIR:       Verzeichnis, in dem die Objektdateien abgelegt werden
#                  sollen.
#    DEPDIR:       Verzeichnis, in dem die Abhaengigkeitsdateien abgelegt werden
#                  sollen
#    DRIVE_HD:     Festplatten-/USB-Device, auf das das System-Image
#                  geschrieben wird (Target: bootdisk)
#    DELETE:       Name des Kommandos zum Loeschen von Dateien
#    ASM:          Zu benutzender Assembler
#    CC/CXX:       Zu benutzender C/C++-Compiler
#    CFLAGS:       Flags fuer den C-Compileraufruf
#    CXXFLAGS:     Flags fuer den C++-Compileraufruf
#    QEMU:         Architekturspezifischer Name des QEMU-Programms
#    MKRESCUE:     Name des GRUB mkrescue-Programms

VERBOSE = @
ASMOBJFORMAT = elf64
OBJDIR = ./build
DEPDIR = ./dep
# ACHTUNG: ein falsch angegebenes Laufwerk kann dazu fuehren, dass Daten auf dem
# spezifizierten Laufwerk verloren gehen! Nicht mit root-Rechten ausfuehren!
DRIVE_HD = /dev/sdz
DELETE = rm
ASM = nasm
QEMU ?= qemu-system-x86_64
CC ?= gcc
CXX ?= g++
CFLAGS := $(CFLAGS) -m64 -Wall -Wno-write-strings -fno-stack-protector -nostdlib -I. -g #-DDEBUG
CXXFLAGS := $(CFLAGS) -Wno-non-virtual-dtor -fno-threadsafe-statics -fno-use-cxa-atexit -fno-rtti -fno-exceptions

ifneq ($(shell which grub-mkrescue 2> /dev/null),)
MKRESCUE = grub-mkrescue
endif
ifneq ($(shell which grub2-mkrescue 2> /dev/null),)
MKRESCUE = grub2-mkrescue
endif

# -------------------------------------------------------------------------
# Namen der Unterverzeichnisse mit den Quelltexten

VPATH = $(sort $(dir $(STARTUP_SOURCE) $(CC_SOURCES) $(C_SOURCES) $(ASM_SOURCES)))

# -------------------------------------------------------------------------
# Listen mit den Objektdateien, die beim Kompilieren entstehen:

FIRST_OBJECT = $(addprefix $(OBJDIR)/,$(patsubst %.asm,_%.o, $(notdir $(STARTUP_SOURCE))))
C_OBJECTS = $(notdir $(C_SOURCES:.c=.o))
CC_OBJECTS = $(notdir $(CC_SOURCES:.cc=.o))

DEP_FILES = $(patsubst %.o,$(DEPDIR)/%.d,$(C_OBJECTS))
DEP_FILES += $(patsubst %.o,$(DEPDIR)/%.d,$(CC_OBJECTS))

ASM_OBJECTS = $(patsubst %.asm,_%.o, $(notdir $(ASM_SOURCES)))
OBJPRE = $(addprefix $(OBJDIR)/,$(ASM_OBJECTS) $(C_OBJECTS) $(CC_OBJECTS))

# --------------------------------------------------------------------------
# Default target: Das Image fuer USB-Sticks und QEMU

all: $(OBJDIR)/bootdisk.iso

# --------------------------------------------------------------------------
# Regeln zur Erzeugung der Abhaengigkeitsdateien

$(DEPDIR)/%.d : %.c
	@echo "DEP		$@"
	@if test \( ! \( -d $(@D) \) \) ;then mkdir -p $(@D);fi
	$(VERBOSE) $(CC) $(CFLAGS) -MM -MT $(OBJDIR)/$*.o -MF $@ $<

$(DEPDIR)/%.d : %.cc
	@echo "DEP		$@"
	@if test \( ! \( -d $(@D) \) \) ;then mkdir -p $(@D);fi
	$(VERBOSE) $(CXX) $(CXXFLAGS) -MM -MT $(OBJDIR)/$*.o -MF $@ $<

# --------------------------------------------------------------------------
# Regeln zur Erzeugung der Objektdateien

$(OBJDIR)/%.o : %.c
	@echo "CC		$@"
	@if test \( ! \( -d $(@D) \) \) ;then mkdir -p $(@D);fi
	$(VERBOSE) $(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/%.o : %.cc
	@echo "CXX		$@"
	@if test \( ! \( -d $(@D) \) \) ;then mkdir -p $(@D);fi
	$(VERBOSE) $(CXX) -c $(CXXFLAGS) -o $@ $<

$(OBJDIR)/_%.o : %.asm
	@echo "ASM		$@"
	@if test \( ! \( -d $(@D) \) \) ;then mkdir -p $(@D);fi
	$(VERBOSE) $(ASM) -f $(ASMOBJFORMAT) -o $@ $<

# --------------------------------------------------------------------------
# Gelinktes System

$(OBJDIR)/system: $(FIRST_OBJECT) $(OBJPRE)
	@echo "LD		$@"
	@if test \( ! \( -d $(@D) \) \) ;then mkdir -p $(@D);fi
	$(VERBOSE) $(CXX) $(CXXFLAGS) -static -z max-page-size=0x1000 -e startup -T sections -o $(OBJDIR)/system $(FIRST_OBJECT) $(OBJPRE)

# --------------------------------------------------------------------------
# 'bootdisk.iso' besteht aus dem System und einem Bootloader (GRUB) mit
# Bootblock und Setup-Code. Das System wird per Multiboot gestartet, so dass
# es sich nicht um den Wechsel in den Protected Mode oder den Setup aus dem
# BIOS heraus kuemmern muss.

$(OBJDIR)/bootdisk.iso : $(OBJDIR)/system
	@echo "BUILD		$@"
	@if test \( ! \( -d $(@D) \) \) ;then mkdir -p $(@D);fi
	$(VERBOSE) cp $< isofiles/boot/system
	$(VERBOSE) $(MKRESCUE) -o $@ isofiles

# --------------------------------------------------------------------------
# 'clean' loescht das generierte System, die Objektdateien und die
# Abhaengigkeitsdateien

clean:	
	@echo "RM		$(OBJDIR)"
	$(VERBOSE) rm -rf $(OBJDIR)
	@echo "RM		$(DEPDIR)"
	$(VERBOSE) rm -rf $(DEPDIR)

# --------------------------------------------------------------------------
# 'vorgabe%' importiert neue Dateien aus einer Vorgabe (2 bis 7) in das
# Arbeitsverzeichnis, so dass mit der naechsten Aufgabe begonnen werden kann.
vorgabe%:
	@echo "EXTRACT         /home/bsb/vorgaben/$@.tar.gz"
	$(VERBOSE) tar --strip-components=1 --keep-old-files -xvf /home/bsb/vorgaben/$@.tar.gz

# --------------------------------------------------------------------------
# 'bootdisk' erzeugt zunaechst das System, falls das noch nicht geschehen ist.
# Danach wird das System auf das spezifizierte Laufwerk geschrieben, welches
# sowohl eine Festplatte als auch ein USB-Stick sein kann.
# ACHTUNG: ein falsch angegebenes Laufwerk kann dazu fuehren, dass Daten auf dem
# spezifizierten Laufwerk verloren gehen! Nicht mit root-Rechten ausfuehren!

bootdisk: $(OBJDIR)/bootdisk.iso
	@echo "CP		$<"
	$(VERBOSE) cp $< $(DRIVE_HD)

# --------------------------------------------------------------------------
# 'qemu' ruft den qemu-Emulator mit dem System auf.

qemu: $(OBJDIR)/bootdisk.iso
	$(QEMU) -drive file=build/bootdisk.iso,format=raw -k en-us

# --------------------------------------------------------------------------
# 'qemu-smp' ruft den qemu-Emulator mit SMP-Support und 2 CPUs mit dem System auf.

qemu-smp: $(OBJDIR)/bootdisk.iso
	$(QEMU) -drive file=build/bootdisk.iso,format=raw -k en-us -smp 2

# --------------------------------------------------------------------------
# 'qemu-gdb' ruft den qemu-Emulator mit aktiviertem GDB-Stub mit dem System
# auf, sodass es per GDB oder DDD inspiziert werden kann.

qemu-gdb: $(OBJDIR)/bootdisk.iso
	$(VERBOSE) echo "target remote localhost:$(shell echo $$(( $$(id -u) + 1023 )))" > /tmp/gdbcommands.$(shell id -u)
	$(QEMU) -drive file=build/bootdisk.iso,format=raw -k en-us -gdb tcp::$(shell echo $$(( $$(id -u) + 1023 )))

# --------------------------------------------------------------------------
# 'gdb' startet den GDB-Debugger und verbindet sich mit dem GDB-Stub des vorher
# gestarteten QEMU.
# Achtung: gdb unterstuetzt derzeit (2017) keine Systeme, die zur Laufzeit
# vom Protected Mode in den Long Mode wechseln. Der gdb darf daher erst
# gestartet werden, wenn das Betriebssystem in qemu bereits erfolgreich in den
# Long Mode gewechselt ist -- ein Start mit `qemu -S` ist nicht moeglich.

gdb:
	gdb -x /tmp/gdbcommands.$(shell id -u) $(OBJDIR)/system

# --------------------------------------------------------------------------
# 'ddd' startet den DDD-Debugger und verbindet sich mit dem GDB-Stub des vorher
# gestarteten QEMU.

ddd:
	ddd --gdb -x /tmp/gdbcommands.$(shell id -u) $(OBJDIR)/system

# --------------------------------------------------------------------------
# Einbindung der Abhaengigkeitsdateien

ifneq ($(MAKECMDGOALS),clean)
-include $(DEP_FILES)
endif

.PHONY: clean bootdisk gdb ddd qemu qemu-smp qemu-gdb
