/* $Id$ */

/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             C G A _ S C R E E N                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe dieser Klasse kann man auf den Bildschirm des PCs zugreifen.    */
/* Der Zugriff erfolgt direkt auf der Hardwareebene, d.h. ueber den Bild-    */
/* schirmspeicher bzw. die I/O-Ports der Grafikkarte.                        */
/*****************************************************************************/

#include "machine/cgascr.h"

void CGA_Screen::show (int x, int y, char c, unsigned char attrib) {
    char *CGA_START = (char *)0xb8000;
    char *pos;
    pos = CGA_START + 2*(x + y*80);
    *pos = c;
    *(pos + 1) = attrib;
}

void CGA_Screen::setpos (int x, int y) {

}

void CGA_Screen::getpos (int &x, int &y) {

}

void CGA_Screen::print (char* text, int length, unsigned char attrib) {

}
