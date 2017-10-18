/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse O_Stream enthaelt die Definition des << Operators fuer die     */
/* wichtigsten der vordefinierten Datentypen und realisiert somit die        */
/* bekannte Ausgabefunktion der C++ iO_Stream Bibliothek. Zur Zeit wird die  */
/* Darstellung von Zeichen, Zeichenketten und ganzen Zahlen unterstuetzt.    */
/* Ein weiterer << Operator erlaubt die Verwendung von Manipulatoren.        */
/*                                                                           */
/* Neben der Klasse O_Stream sind hier auch die Manipulatoren hex, dec, oct  */
/* und bin fuer die Wahl der Basis bei der Zahlendarstellung, sowie endl     */
/* fuer den Zeilenumbruch definiert.                                         */
/*****************************************************************************/

#ifndef __o_stream_include__
#define __o_stream_include__

#include "object/strbuf.h"

class O_Stream
/* Hier muesst ihr selbst Code vervollstaendigen */         
 {
private:
      O_Stream(const O_Stream &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */     
 };

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          M A N I P U L A T O R E N                        */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die folgenden Funktionen erhalten und liefern jeweils eine Referenz auf   */
/* ein O_Stream Objekt. Da die Klasse O_Stream einen Operator << fuer        */
/* derartige Funktionen definiert, koennen sie mit Hilfe dieses Operators    */
/* aufgerufen und sogar in weitere Eingaben eingebettet werden.              */
/* Aufgabe der Manipulatoren ist, die Darstellung der nachfolgenden Ausgaben */
/* zu beeinflussen, z.B durch die Wahl des Zahlensystems.                    */
/*---------------------------------------------------------------------------*/

// ENDL: fuegt einen Zeilenumbruch in die Ausgabe ein.
/* Hier muesst ihr selbst Code vervollstaendigen */ 

// BIN: waehlt das binaere Zahlensystem aus.
/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
// OCT: waehlt das oktale Zahlensystem aus.
/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
// DEC: waehlt das dezimale Zahlensystem aus.
/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
// HEX: waehlt das hexadezimale Zahlensystem aus.
/* Hier muesst ihr selbst Code vervollstaendigen */ 

#endif

