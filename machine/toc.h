/* $Id$ */

/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 T O C                                     */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Struktur toc dient dazu, bei einem Koroutinenwechsel die Werte der    */
/* nicht-fluechtigen Register zu sichern.                                    */
/* Bei der vom GNU C-Compiler genutzten System V AMD64 ABI sind RBP, RBX und */
/* R12 bis R15 nicht-flüchtige Register, die beim Kontextwechsel von Hand    */
/* gesichert werden müssen. Zusätzlich gibt es 108 Byte an nicht-flüchtigem  */
/* Extended CPU State, die aber nur wichtig sind, wenn Komponenten wie die   */
/* FPU oder SIMD-Instruktionen genutzt werden.                               */
/*                                                                           */
/* Achtung: Fuer den Zugriff auf die Elemente von struct toc aus einer       */
/* Assemblerfunktion heraus werden in der Datei toc.inc Namen fuer die       */
/* benoetigten Abstaende der einzelnen Elemente zum Anfang der Struktur      */
/* definiert. Damit dann auch auf die richtigen Elemente zugegriffen wird,   */
/* sollten sich die Angaben von toc.h und toc.inc exakt entsprechen.         */
/* Wer also toc.h aendert, muss auch toc.inc anpassen (und umgekehrt.)       */
/*****************************************************************************/

#ifndef __toc_include__
#define __toc_include__

// TOC: ("thread of control")
//
struct toc {
	void *rbx;
	void *r12;
	void *r13;
	void *r14;
	void *r15;
	void *rbp;
	void *rsp;
	char fpu[108]; // Optional: 108 Byte extended CPU state (MMX, SSE, ...)
};

#endif
