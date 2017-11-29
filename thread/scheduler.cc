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

void Scheduler::ready(Entrant &that) {
    readyList.enqueue(&that);
}

void Scheduler::schedule() {
    activeCoroutine = (Coroutine *) readyList.dequeue();
    // active().go(); todo
}

void Scheduler::exit() {
    // todo
}

void Scheduler::kill(Entrant &that) {
    readyList.remove(&that);
}

void Scheduler::resume() {
    // todo
    readyList.enqueue((Entrant *) active());
}

