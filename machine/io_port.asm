; $Id$

;*****************************************************************************
;* Betriebssysteme                                                           *
;*---------------------------------------------------------------------------*
;*                                                                           *
;*                             I O _ P O R T                                 *
;*                                                                           *
;*---------------------------------------------------------------------------*
;* Die hier definierten Funktionen stellen die Maschinebefehle 'in' und      *
;* 'out' fuer die Klasse IO_Port zur Verfuegung.                             *
;*****************************************************************************

; EXPORTIERTE FUNKTIONEN

[GLOBAL outb]
[GLOBAL outw]
[GLOBAL inb]
[GLOBAL inw]

; IMPLEMENTIERUNG DER FUNKTIONEN

[SECTION .text]
	
; OUTB: Byteweise Ausgabe eines Wertes ueber einen I/O-Port.
;
;       C-Prototyp: void outb (int port, int value);

outb:
	push   rbp
	mov    rbp, rsp
	mov    rdx, rdi
	mov    rax, rsi
	out    dx, al
	pop    rbp
	ret

; OUTW: Wortweise Ausgabe eines Wertes ueber einen I/O-Port.
;
;       C-Prototyp: void outw (int port, int value);

outw:
	push   rbp
	mov    rbp, rsp
	mov    rdx, rdi
	mov    rax, rsi
	out    dx, ax
	pop    rbp
	ret

; INB: Byteweises Einlesen eines Wertes ueber einen I/O-Port.
;
;      C-Prototyp: int inb (int port);

inb:
	push   rbp
	mov    rbp, rsp
	mov    rdx, rdi
	mov    rax, rsi
	in     al, dx
	pop    rbp
	ret

; INW: Wortweises Einlesen eines Wertes ueber einen I/O-Port.
;
;      C-Prototyp: int inw (int port);

inw:
	push   rbp
	mov    rbp, rsp
	mov    rdx, rdi
	mov    rax, rsi
	in     ax, dx
	pop    rbp
	ret
