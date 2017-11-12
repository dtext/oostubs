/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Tastaturtreiber.                                                          */
/*****************************************************************************/

#ifndef __Keyboard_include__
#define __Keyboard_include__

#include "machine/keyctrl.h"
#include "guard/gate.h"
#include "machine/key.h"

class Keyboard : Gate, Keyboard_Controller {
private:
    Keyboard(const Keyboard &copy); // Verhindere Kopieren
    Keyboard_Controller keyboard;
public:
    Keyboard() {}

    void plugin();

    void trigger();

};

#endif
