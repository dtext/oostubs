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

bool Keyboard::prologue() {
    press = key_hit();
    return true;
}

void Keyboard::epilogue() {
    if (press.scancode() == Key::scan::del && press.ctrl() && press.alt()) {
        reboot();
        cout << "reboot" << flush;
    }
    if (press.valid()) {
        semaphore.signal();
    }
}

Key Keyboard::getkey() {
    semaphore.wait();
    return press;
}