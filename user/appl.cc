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
#include "device/keyboard.h"
#include "machine/plugbox.h"
#include "machine/cpu.h"

void Application::action() {
    CPU cpu;
    cpu.enable_int();
    Keyboard keyboard;
    keyboard.plugin();
    CGA_Screen scr;
    while (1) {
        scr.show(79, 0, '_', 15);
    }
}
