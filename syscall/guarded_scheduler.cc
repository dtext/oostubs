/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    G U A R D E D _ S C H E D U L E R                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Scheduler.                                  */
/*****************************************************************************/

#include "guarded_scheduler.h"
#include "guard/secure.h"

Guarded_Scheduler scheduler;

void Guarded_Scheduler::ready(Thread &that) {
    Secure section;
    Scheduler::ready(that);
}

void Guarded_Scheduler::exit() {
    Secure section;
    Scheduler::exit();
}

void Guarded_Scheduler::kill(Thread &that) {
    Secure section;
    Scheduler::kill(that);
}

void Guarded_Scheduler::resume() {
    Secure section;
    Scheduler::resume();
}
