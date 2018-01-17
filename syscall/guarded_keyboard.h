/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ K E Y B O A R D                         */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zur Tastatur.                                   */
/*****************************************************************************/

#ifndef __Guarded_Keyboard_include__
#define __Guarded_Keyboard_include__

#include <device/keyboard.h>

class Guarded_Keyboard : public Keyboard {
private:
    Guarded_Keyboard(const Guarded_Keyboard &copy); // Verhindere Kopieren
public:
    Guarded_Keyboard() {}

    Key getkey();
};

extern Guarded_Keyboard keyboard;

#endif
