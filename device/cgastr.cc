/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         C G A _ S T R E A M                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse CGA_Stream ermoeglicht die Ausgabe verschiedener Datentypen    */
/* als Zeichenketten auf dem CGA Bildschirm eines PCs.                       */
/* Fuer weitergehende Formatierung oder spezielle Effekte stehen die         */
/* Methoden der Klasse CGA_Screen zur Verfuegung.                            */
/*****************************************************************************/

#include "device/cgastr.h"

CGA_Stream cout;

void CGA_Stream::flush() {
    CGA_Screen::print(this->buffer, this->getIndex(), 15);
    this->resetBuffer();
}