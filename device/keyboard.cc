/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Tastaturtreiber.                                                          */
/*****************************************************************************/

#include "keyboard.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "device/cgastr.h"
#include "machine/cpu.h"

void Keyboard::plugin() {
    plugbox.assign(plugbox.keyboard, *this);
    pic.allow(pic.keyboard);
}

void Keyboard::trigger() {
    Key myKey;
    myKey = keyboard.key_hit();

    if (myKey.ascii() == 97 /*&& myKey.ctrl()*/ && myKey.alt()) {
        keyboard.reboot();
        cout << "reboot";
        cout.flush();
    }
    if (myKey.valid()) {
        cout << myKey.ascii();
        cout.flush();
    }
}
