/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

/* INCLUDES */

#include "user/appl.h"
#include "device/cgastr.h"
#include "machine/keyctrl.h"
#include "machine/pic.h"


void Application::action() {
    Keyboard_Controller keyboard;

    int i = 768;
    int j = -480;

    unsigned long l = (unsigned long) -1;

    // print some numbers
    cout << "Integer of value " << i
         << " in hex: " << hex << i
         << ", octal: " << oct << i
         << " and binary: " << bin << i << '\n';

    cout << "Negative Values work, too: " << dec << j << '\n';

    cout << "Look! A very large number: " << l << '\n';
    cout.flush();

    PIC pic;
    pic.allow(PIC::keyboard);
    pic.forbid(PIC::keyboard);
    pic.allow(PIC::timer);
    if(pic.is_masked(PIC::timer)){
        cout << "timer is masked! " << endl;
        cout.flush();
    }
    if(pic.is_masked(PIC::keyboard)){
        cout << "keyboard is masked! " << endl;
        cout.flush();
    }


    // read stuff from keyboard
    Key myKey;
    while (true) {
        myKey = keyboard.key_hit();
        if(myKey.valid()) {
            cout << myKey.ascii();
            cout.flush();
        }
    }
}
