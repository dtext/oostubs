#ifndef __screen_include__
#define __screen_include__

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

#include "machine/io_port.h"

class CGA_Screen
 {
private:
/* Hier muesst ihr selbst Code vervollstaendigen */ 

   CGA_Screen(const CGA_Screen &copy); // Verhindere Kopieren
public:
   CGA_Screen()
/* Hier muesst ihr selbst Code vervollstaendigen */ 
 {}

/* Hier muesst ihr selbst Code vervollstaendigen */ 
 };

/* Hier muesst ihr selbst Code vervollstaendigen */ 

#endif

