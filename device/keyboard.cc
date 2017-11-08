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
    PIC pic;
    pic.allow(pic.keyboard);
}

void Keyboard::trigger() {
    Key myKey;
    Keyboard_Controller keyboard;
    myKey = keyboard.key_hit();

    cout << myKey.ctrl()+1 << endl;
    cout.flush();
    if (myKey.ascii() == 97 /*&& myKey.ctrl()*/ && myKey.alt()) {
        //keyboard.reboot();
        cout << "reboot";
        cout.flush();
    }
    if (myKey.valid()) {
        cout << myKey.ascii();
        cout.flush();
    }
}
