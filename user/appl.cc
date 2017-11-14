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
#include "device/keyboard.h"
#include "machine/cpu.h"

void Application::action() {
    CPU cpu;
    cpu.enable_int();
    Keyboard keyboard;
    keyboard.plugin();
    int z;
    while (1) {
        cpu.disable_int();
        cout.setpos(79, 0);
        cout << z++;
        cout.flush();
        cpu.enable_int();
    }
}
