; $Id$

;******************************************************************************
;* Betriebssysteme                                                            *
;*----------------------------------------------------------------------------*
;*                                                                            *
;*                        S T A R T U P . A S M                               *
;*                                                                            *
;*----------------------------------------------------------------------------*
;* Die Funktion 'startup' ist der Eintrittspunkt des eigentlichen Systems.    *
;* Die Umschaltung in den 32-bit 'Protected Mode' ist bereits erfolgt. Es     *
;* wird alles vorbereitet, damit so schnell wie möglich mit der Ausführung    *
;* von C++-Code im 64-bit 'Long Mode' begonnen werden kann.                   *
;******************************************************************************

;
;   Konstanten
;

; Stack fuer die main-Funktion
STACKSIZE: equ 65536

; Basisadresse des Grafikspeichers
CGA: equ 0xB8000

; 254 GB maximale RAM-Groesse fuer die Seitentabelle
MAX_MEM: equ 254

; Multiboot-Konstanten
MULTIBOOT_PAGE_ALIGN     equ   1<<0
MULTIBOOT_MEMORY_INFO    equ   1<<1

; Magic Number fuer Multiboot
MULTIBOOT_HEADER_MAGIC   equ   0x1badb002

; Multiboot-Flags (ELF-spezifisch!)
MULTIBOOT_HEADER_FLAGS   equ   MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO
MULTIBOOT_HEADER_CHKSUM  equ   -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
MULTIBOOT_EAX_MAGIC      equ   0x2badb002

; Speicherplatz fuer die Seitentabelle

[GLOBAL pagetable_start]
pagetable_start:  equ 0x103000

[GLOBAL pagetable_end]
pagetable_end:  equ 0x200000

;
;   System
;

; Von uns bereitgestellte Funktionen
[GLOBAL startup]
[GLOBAL idt]
[GLOBAL __cxa_pure_virtual]
[GLOBAL _ZdlPv]
[GLOBAL _ZdlPvj]
[GLOBAL _ZdlPvm]

; Funktionen aus dem C-Teil des Betriebssystems
[EXTERN main]
[EXTERN guardian]

; Vom Compiler bereitgestellte Adressen
[EXTERN ___BSS_START__]
[EXTERN ___BSS_END__]
[EXTERN __init_array_start]
[EXTERN __init_array_end]
[EXTERN __fini_array_start]
[EXTERN __fini_array_end]

[SECTION .text]

;
;   System-Start, Teil 1 (im 32-bit Protected Mode)
;
;   Initialisierung von GDT und Seitentabelle und Wechsel in den 64-bit
;   Long Mode.
;

[BITS 32]

	jmp    startup  ; Sprung an den Start (fuer den konventionellen System-Code)
	align  4        ; 32-bit Alignment fuer GRUB

;
;   Multiboot-Header zum Starten mit GRUB oder QEMU (ohne BIOS)
;

	dd MULTIBOOT_HEADER_MAGIC
	dd MULTIBOOT_HEADER_FLAGS
	dd MULTIBOOT_HEADER_CHKSUM
	dd 0 ; header_addr (wird ignoriert)
	dd 0 ; load_addr (wird ignoriert)
	dd 0 ; load_end_addr (wird ignoriert)
	dd 0 ; bss_end_addr (wird ignoriert)
	dd 0 ; entry_addr (wird ignoriert)
	dd 0 ; mode_type (wird ignoriert)
	dd 0 ; width (wird ignoriert)
	dd 0 ; height (wird ignoriert)
	dd 0 ; depth (wird ignoriert)

;
;  GRUB Einsprungspunkt
;

startup:
	cld              ; GCC-kompilierter Code erwartet das so
	cli              ; Interrupts ausschalten
	lgdt   [gdt_80]  ; Neue Segmentdeskriptoren setzen

	; Globales Datensegment
	mov    eax, 3 * 0x8
	mov    ds, ax
	mov    es, ax
	mov    fs, ax
	mov    gs, ax

	; Stack festlegen
	mov    ss, ax
	mov    esp, init_stack+STACKSIZE

;
;  Umschalten in den 64 Bit Long-Mode
;

init_longmode:
	; Adresserweiterung (PAE) aktivieren
	mov    eax, cr4
	or     eax, 1 << 5
	mov    cr4, eax

	; Seitentabelle anlegen (Ohne geht es nicht)
	call   setup_paging

	; Long-Mode (fürs erste noch im Compatibility-Mode) aktivieren
	mov    ecx, 0x0C0000080 ; EFER (Extended Feature Enable Register) auswaehlen
	rdmsr
	or     eax, 1 << 8 ; LME (Long Mode Enable)
	wrmsr

	; Paging aktivieren
	mov    eax, cr0
	or     eax, 1 << 31
	mov    cr0, eax

	; Sprung ins 64 Bit-Codesegment -> Long-Mode wird vollständig aktiviert
	jmp    2 * 0x8 : longmode_start

;
;   Anlegen einer (provisorischen) Seitentabelle mit 2 MB Seitengröße, die die
;   ersten MAX_MEM GB direkt auf den physikalischen Speicher abbildet.
;   Dies ist notwendig, da eine funktionierende Seitentabelle für den Long-Mode
;   vorausgesetzt wird. Mehr Speicher darf das System im Moment nicht haben.
;

setup_paging:
	; PML4 (Page Map Level 4 / 1. Stufe)
	mov    eax, pdp
	or     eax, 0xf
	mov    dword [pml4+0], eax
	mov    dword [pml4+4], 0

	; PDPE (Page-Directory-Pointer Entry / 2. Stufe) für aktuell 16GB
	mov    ecx, 0
	mov    eax, pd
	or     eax, 0x7           ; Adresse der ersten Tabelle (3. Stufe) mit Flags.
fill_tables2:
	cmp    ecx, MAX_MEM       ; MAX_MEM Tabellen referenzieren
	je     fill_tables2_done
	mov    dword [pdp + 8*ecx + 0], eax
	mov    dword [pdp + 8*ecx + 4], 0
	add    eax, 0x1000        ; Die Tabellen sind je 4kB groß
	inc    ecx
	ja     fill_tables2
fill_tables2_done:

	; PDE (Page Directory Entry / 3. Stufe)
	mov    ecx, 0
	mov    eax, 0x0 | 0x87    ; Startadresse 0 + Flags
fill_tables3:
	cmp    ecx, 512*MAX_MEM   ; MAX_MEM Tabellen mit je 512 Einträgen füllen
	je     fill_tables3_done
	mov    dword [pd + 8*ecx + 0], eax
	mov    dword [pd + 8*ecx + 4], 0
	add    eax, 0x200000      ; 2 MB je Seite
	inc    ecx
	ja     fill_tables3
fill_tables3_done:

	; Basiszeiger auf PML4 setzen
	mov    eax, pml4
	mov    cr3, eax
	ret

;
;   System-Start, Teil 2 (im 64-bit Long-Mode)
;
;   Das BSS-Segment wird gelöscht und die IDT die PICs initialisiert.
;   Anschließend werden die Konstruktoren der globalen C++-Objekte und
;   schließlich main() ausgeführt.
;

longmode_start:
[BITS 64]
	; BSS löschen
	mov    rdi, ___BSS_START__
clear_bss:
	mov    byte [rdi], 0
	inc    rdi
	cmp    rdi, ___BSS_END__
	jne    clear_bss

	; IDT und PICs initialisieren
	call   setup_idt
	call   reprogram_pics
	call   setup_cursor

	fninit         ; FPU aktivieren
	call   _init   ; Konstruktoren globaler Objekte ausführen
	call   main    ; Aufruf des C / C++ Betriebssystemkerns
	call   _fini   ; Destruktoren ausführen
	cli            ; Hier sollten wir nicht hinkommen
	hlt

;
;   Unterbrechungsbehandlung
;

; Spezifischer Kopf der Unterbrechungsbehandlungsroutinen
%macro wrapper 1
wrapper_%1:
	push   rbp
	mov    rbp, rsp
	push   rax
	mov    al, %1
	jmp    wrapper_body
%endmacro

; ... wird automatisch erzeugt.
%assign i 0
%rep 256
wrapper i
%assign i i+1
%endrep

; Gemeinsamer Rumpf
wrapper_body:
	; Das erwartet der gcc so
	cld
	; Flüchtige Register sichern
	push   rcx
	push   rdx
	push   rdi
	push   rsi
	push   r8
	push   r9
	push   r10
	push   r11

	; Der generierte Wrapper liefert nur 8 Bit
	and    rax, 0xff

	; Nummer der Unterbrechung als Argument übergeben
	mov    rdi, rax
	call   guardian

	; Flüchtige Register wiederherstellen
	pop    r11
	pop    r10
	pop    r9
	pop    r8
	pop    rsi
	pop    rdi
	pop    rdx
	pop    rcx

	; ... auch die aus dem Wrapper
	pop    rax
	pop    rbp

	; Fertig!
	iretq

;
; Relokation der Eintraege in der IDT und Setzen des IDTR
;

setup_idt:
	mov    rax, wrapper_0

	; Bits 0..15 -> ax, 16..31 -> bx, 32..64 -> edx
	mov    rbx, rax
	mov    rdx, rax
	shr    rdx, 32
	shr    rbx, 16

	mov    r10, idt   ; Zeiger auf das aktuelle Interrupt-Gate
	mov    rcx, 255   ; Zähler
.loop:
	add    [r10+0], ax
	adc    [r10+6], bx
	adc    [r10+8], edx
	add    r10, 16
	dec    rcx
	jge    .loop

	lidt   [idt_descr]
	ret

;
; Cursor blinken lassen (wird von GRUB ausgestellt)
;

setup_cursor:
	mov al, 0x0a
	mov dx, 0x3d4
	out dx, al
	call delay
	mov dx, 0x3d5
	in al, dx
	call delay
	and al, 0xc0
	or al, 14
	out dx, al
	call delay
	mov al, 0x0b
	mov dx, 0x3d4
	out dx, al
	call delay
	mov dx, 0x3d5
	in al, dx
	call delay
	and al, 0xe0
	or al, 15
	out dx, al
	ret

;
; Neuprogrammierung der PICs (Programmierbare Interrupt-Controller), damit
; alle 15 Hardware-Interrupts nacheinander in der idt liegen.
;

reprogram_pics:
	mov    al, 0x11   ; ICW1: 8086-Modus mit ICW4
	out    0x20, al
	call   delay
	out    0xa0, al
	call   delay
	mov    al, 0x20   ; ICW2 Master: IRQ # Offset (32)
	out    0x21, al
	call   delay
	mov    al, 0x28   ; ICW2 Slave: IRQ # Offset (40)
	out    0xa1, al
	call   delay
	mov    al, 0x04   ; ICW3 Master: Slaves an IRQs
	out    0x21, al
	call   delay
	mov    al, 0x02   ; ICW3 Slave: Verbunden mit IRQ2 des Masters
	out    0xa1, al
	call   delay
	mov    al, 0x03   ; ICW4: 8086-Modus und automatischer EOI
	out    0x21, al
	call   delay
	out    0xa1, al
	call   delay

	mov    al, 0xff   ; Hardware-Interrupts durch PICs
	out    0xa1, al   ; ausmaskieren. Nur der Interrupt 2,
	call   delay      ; der der Kaskadierung der beiden
	mov    al, 0xfb   ; PICs dient, ist erlaubt.
	out    0x21, al

	ret

;
; Konstruktoren globaler Objekte ausführen
;

_init:
	mov    rbx, __init_array_start
_init_loop:
	cmp    rbx, __init_array_end
	je     _init_done
	mov    rax, [rbx]
	call   rax
	add    rbx, 8
	ja     _init_loop
_init_done:
	ret

;
; Destruktoren globaler Objekte ausführen
;

_fini:
	mov    rbx, __fini_array_start
_fini_loop:
	cmp    rbx, __fini_array_end
	je     _fini_done
	mov    rax, [rbx]
	call   rax
	add    rbx, 8
	ja     _fini_loop
_fini_done:
	ret

;
; Kurze Verzögerung für in/out-Befehle
;

delay:
	jmp    .L2
.L2:
	ret

;
; Funktionen für den C++ Compiler. Diese Label müssen für den Linker
; definiert sein; da bei OOStuBS keine Freigabe des Speichers erfolgt, können
; die Funktionen aber leer sein.
;

__cxa_pure_virtual: ; "virtual" Methode ohne Implementierung aufgerufen
_ZdlPv:             ; void operator delete(void*)
_ZdlPvj:            ; void operator delete(void*, unsigned int) fuer g++ 6.x
_ZdlPvm:            ; void operator delete(void*, unsigned long) fuer g++ 6.x
	ret

[SECTION .data]

;
; Segment-Deskriptoren
;

gdt:
	dw  0,0,0,0   ; NULL-Deskriptor

	; 32-Bit-Codesegment-Deskriptor
	dw  0xFFFF    ; 4Gb - (0x100000*0x1000 = 4Gb)
	dw  0x0000    ; base address=0
	dw  0x9A00    ; code read/exec
	dw  0x00CF    ; granularity=4096, 386 (+5th nibble of limit)

	; 64-Bit-Codesegment-Deskriptor
	dw  0xFFFF    ; 4Gb - (0x100000*0x1000 = 4Gb)
	dw  0x0000    ; base address=0
	dw  0x9A00    ; code read/exec
	dw  0x00AF    ; granularity=4096, 386 (+5th nibble of limit), Long-Mode

	; Datensegment-Deskriptor
	dw  0xFFFF    ; 4Gb - (0x100000*0x1000 = 4Gb)
	dw  0x0000    ; base address=0
	dw  0x9200    ; data read/write
	dw  0x00CF    ; granularity=4096, 386 (+5th nibble of limit)

gdt_80:
	dw  4*8 - 1   ; GDT Limit=24, 4 GDT Eintraege - 1
	dq  gdt       ; Adresse der GDT

;
; Interrupt Descriptor Table mit 256 Einträgen
;

idt:
%macro idt_entry 1
	dw  (wrapper_%1 - wrapper_0) & 0xffff ; Offset 0 .. 15
	dw  0x0000 | 0x8 * 2 ; Selector zeigt auf den 64-Bit-Codesegment-Deskriptor der GDT
	dw  0x8e00 ; 8 -> interrupt is present, e -> 80386 32-bit interrupt gate
	dw  ((wrapper_%1 - wrapper_0) & 0xffff0000) >> 16 ; Offset 16 .. 31
	dd  ((wrapper_%1 - wrapper_0) & 0xffffffff00000000) >> 32 ; Offset 32..63
	dd  0x00000000 ; Reserviert
%endmacro

%assign i 0
%rep 256
idt_entry i
%assign i i+1
%endrep

idt_descr:
	dw  256*8 - 1    ; 256 Einträge
	dq idt

[SECTION .bss]

[GLOBAL MULTIBOOT_FLAGS]
[GLOBAL MULTIBOOT_LOWER_MEM]
[GLOBAL MULTIBOOT_UPPER_MEM]
[GLOBAL MULTIBOOT_BOOTDEVICE]
[GLOBAL MULTIBOOT_CMDLINE]
[GLOBAL MULTIBOOT_MODULES_COUNT]
[GLOBAL MULTIBOOT_MODULES_ADDRESS]

MULTIBOOT_FLAGS:            resd 1
MULTIBOOT_LOWER_MEM:        resd 1
MULTIBOOT_UPPER_MEM:        resd 1
MULTIBOOT_BOOTDEVICE:       resd 1
MULTIBOOT_CMDLINE:          resd 1
MULTIBOOT_MODULES_COUNT:    resd 1
MULTIBOOT_MODULES_ADDRESS:  resd 1

global init_stack:data (init_stack.end - init_stack)
init_stack:
	resb STACKSIZE
.end:

[SECTION .global_pagetable]

[GLOBAL pml4]
[GLOBAL pdp]
[GLOBAL pd]

pml4:
	resb   4096
	alignb 4096

pdp:
	resb   MAX_MEM*8
	alignb 4096

pd:
	resb   MAX_MEM*4096
