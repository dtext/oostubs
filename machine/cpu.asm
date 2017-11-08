;*****************************************************************************
;* Betriebssysteme                                                           *
;*---------------------------------------------------------------------------*
;*                                                                           *
;*                                   C P U                                   *
;*                                                                           *
;*---------------------------------------------------------------------------*
;* Dieses Assembler-Modul unterstuetzt die Klasse CPU.                       *
;*****************************************************************************

; EXPORTIERTE FUNKTIONEN

[GLOBAL int_enable]
[GLOBAL int_disable]
[GLOBAL cpu_idle]
[GLOBAL cpu_halt]

; IMPLEMENTIERUNG DER FUNKTIONEN

[SECTION .text]

; INT_ENABLE: Erlauben von (Hardware-)Interrupts
;
;       C-Prototyp: void int_enable ();

int_enable:
	sti
	ret

; INT_DISABLE: Interrupts werden ignoriert/verboten
;
;       C-Prototyp: void int_disable ();

int_disable:
	cli
	ret

; CPU_IDLE : Erlaubt Interrupts und haelt den Prozessor (bis zu einem
;            Interrupt) an
;
; C Prototyp: void cpu_idle (void)

cpu_idle:
	sti ; STI und HLT werden atomar ausgefuehrt
	hlt
        ret

; CPU_HALT : Haelt den Prozessor an.
;
; C Prototyp: void cpu_halt (void)

cpu_halt:
	cli
	hlt
