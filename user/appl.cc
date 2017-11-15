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
#include "guard/secure.h"

void Application::action() {
    cpu.enable_int();
    keyboard.plugin();
    int z;
    while (1) {
        cout.setpos(79, 0);
        cout << z++;
        cout.flush();
    }
}
