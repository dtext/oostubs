; $Id$

;*****************************************************************************
;* Betriebssysteme                                                           *
;*---------------------------------------------------------------------------*
;*                                                                           *
;*                                  T O C                                    *
;*                                                                           *
;*---------------------------------------------------------------------------*
;* Assemblerdarstellung der struct toc aus toc.h                             *
;*                                                                           *
;* Die Reihenfolge der Registerbezeichnungen muss unbedingt mit der von      *
;* struct toc uebereinstimmen.                                               *
;*****************************************************************************

; STRUKTUREN

; TOC: nicht-fluechtige Register eines x86_64-Prozessors (System V AMD64 ABI)

; Die folgenden Angaben belegen rbx_offset mit dem Wert 0, r12_offset mit 8,
; r13_offset mit 16 und so weiter. Dies entspricht den Abstaenden der Elemente
; rbx, r12, r13 etc. der Struktur toc zum Anfang der Struktur (in Bytes).

[ABSOLUTE 0]
rbx_offset: resq 1
r12_offset: resq 1
r13_offset: resq 1
r14_offset: resq 1
r15_offset: resq 1
rbp_offset: resq 1
rsp_offset: resq 1
fpu_offset: resb 108
