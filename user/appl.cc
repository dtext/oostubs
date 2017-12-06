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

#include <machine/toc.h>
#include <thread/coroutine.h>
#include "user/appl.h"
#include "device/cgastr.h"
#include "my_coroutine.h"
#include "my_other_coroutine.h"

char my_stack[4096];
char my_other_stack[4096];
toc my_toc;
toc my_other_toc;

void my_function(void *a) {
    cout << "Foo" << flush;
    toc_switch(&my_toc, &my_other_toc, 0);
    cout << "Ende" << flush;
    while (1) {}
}

void my_other_function(void *a) {
    cout << "Bar" << flush;
    toc_switch(&my_other_toc, &my_toc, 0);
}

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

    MyOtherCoroutine myOtherCoroutine(my_other_stack + 4096);
    MyCoroutine myCoroutine(my_stack + 4096, &myOtherCoroutine);
    myOtherCoroutine.setCoroutine(&myCoroutine);

    myCoroutine.go();
}
