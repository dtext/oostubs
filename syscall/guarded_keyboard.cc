/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ K E Y B O A R D                         */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zur Tastatur.                                   */
/*****************************************************************************/

#include <machine/key.h>
#include <guard/secure.h>
#include "guarded_keyboard.h"

Guarded_Keyboard keyboard;

Key Guarded_Keyboard::getkey() {
    Secure section;
    return Keyboard::getkey();
}
