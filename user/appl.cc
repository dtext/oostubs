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

#include <thread/coroutine.h>
#include <syscall/guarded_scheduler.h>
#include "user/appl.h"

void Application::action() {
    /*cpu.enable_int();
    keyboard.plugin();
    int z;
    while (1) {
        {
            Secure section;
            cout.setpos(79, 0);
            cout << z++ << flush;
        }
    }*/

    /*toc_settle(&my_toc, (void *) (my_stack + 4096), my_function);
    toc_settle(&my_other_toc, (void *) (my_other_stack + 4096), my_other_function);
    toc_go(&my_toc, 0);*/

    scheduler.resume();
    scheduler.resume();
    while (true) {}
}
