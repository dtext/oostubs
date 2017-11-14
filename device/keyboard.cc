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

void Keyboard::plugin() {
    plugbox.assign(plugbox.keyboard, *this);
    pic.allow(pic.keyboard);
}

void Keyboard::trigger() {
    Key myKey;
    myKey = key_hit();

    if (myKey.ascii() == 97 /*&& myKey.ctrl()*/ && myKey.alt()) {
        reboot();
        cout << "reboot";
        cout.flush();
    }
    if (myKey.valid()) {
        int x, y;
        cout.getpos(x, y);
        cout.setpos(10, 10);
        cout << myKey.ascii();
        cout.flush();
        cout.setpos(x, y);
    }
}
