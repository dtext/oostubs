/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Schedulers.                                           */
/*****************************************************************************/

#include "thread/scheduler.h"
#include "guard/guard.h"

void Scheduler::ready(Entrant &that) {
    readyList.enqueue(&that);
}

void Scheduler::schedule() {
    go(static_cast<Entrant &>(*(readyList.dequeue())));
}

void Scheduler::exit() {
    Entrant *next = 0;
    while(!next){
        next = static_cast<Entrant*>(readyList.dequeue());
        guard.leave();
        cpu.idle();
        guard.enter();
    }
    dispatch(*next);
}

void Scheduler::kill(Entrant &that) {
    if (&that == active())
        exit();
    else
        readyList.remove(&that);
}

void Scheduler::resume() {
    readyList.enqueue((Entrant *) active());

    dispatch(static_cast<Entrant &>(*(readyList.dequeue())));
}
