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
    CGA_Stream stream;
    Keyboard_Controller keyboard;

    char led_number = 0;
    Key myKey;
    while (true) {
        myKey = keyboard.key_hit();
        if(myKey.valid()) {
            stream << myKey.ascii();
            stream.flush();
            keyboard.set_led(led_number,0);
            led_number = led_number + 1 ? led_number < 2 : 0;
            keyboard.set_led(led_number,1);
        }
    }
}
