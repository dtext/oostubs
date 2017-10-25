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
#include "strbuf.h"

enum OutputFormat {
    BIN = 2, OCT = 8, DEC = 10, HEX = 16
};

class O_Stream : public Stringbuffer {
private:
    OutputFormat currentOutputFormat;

    O_Stream(const O_Stream &copy); // Verhindere Kopieren

    O_Stream &convert(unsigned long value);

public:
    O_Stream() {
        currentOutputFormat = DEC;
    }

    O_Stream &operator<<(unsigned char c);

    O_Stream &operator<<(char c);

    O_Stream &operator<<(unsigned short number);

    O_Stream &operator<<(short number);

    O_Stream &operator<<(unsigned int number);

    O_Stream &operator<<(int number);

    O_Stream &operator<<(unsigned long number);

    O_Stream &operator<<(long number);

    O_Stream &operator<<(void *pointer);

    O_Stream &operator<<(char *text);

    O_Stream &operator<<(O_Stream &(*fkt)(O_Stream &));

    void flush() {}

    void setOutputFormat(OutputFormat currentOutputFormat) {
        this->currentOutputFormat = currentOutputFormat;
    }

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

O_Stream &endl(O_Stream &os);

O_Stream &bin(O_Stream &os);

O_Stream &oct(O_Stream &os);

O_Stream &dec(O_Stream &os);

O_Stream &hex(O_Stream &os);

#endif

