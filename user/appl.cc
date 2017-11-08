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

/* GLOBALE VARIABLEN */

extern CGA_Stream kout;

void Application::action() {
    CGA_Stream stream, kout;
    Keyboard_Controller keyboard;

    int i = 768;
    int j = -480;

    unsigned long l = (unsigned long) -1;

    // print some numbers
    kout << "Integer of value " << i
         << " in hex: " << hex << i
         << ", octal: " << oct << i
         << " and binary: " << bin << i << '\n';

    kout << "Negative Values work, too: " << dec << j << '\n';

    kout << "Look! A very large number: " << l << '\n';
    kout.flush();

    // read stuff from keyboard
    Key myKey;
    while (true) {
        myKey = keyboard.key_hit();
        if(myKey.valid()) {
            stream << myKey.ascii();
            stream.flush();
        }
    }
}
