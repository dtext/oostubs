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

Keyboard keyboard;

void Keyboard::plugin() {
    plugbox.assign(plugbox.keyboard, *this);
    pic.allow(pic.keyboard);
}

bool Keyboard::prologue() {
    press = key_hit();
    return true;
}

void Keyboard::epilogue() {
    if (press.ascii() == 97 /*&& press.ctrl()*/ && press.alt()) {
        reboot();
        cout << "reboot";
        cout.flush();
    }
    if (press.valid()) {
        int x, y;
        cout.getpos(x, y);
        cout.setpos(10, 10);
        cout << press.ascii();
        cout.flush();
        cout.setpos(x, y);
    }
}