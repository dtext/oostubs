/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Schedulers.                                           */
/*****************************************************************************/

#ifndef __schedule_include__
#define __schedule_include__

#include "thread/dispatch.h"
#include "thread/entrant.h"
#include "object/queue.h"

class Scheduler : public Dispatcher {
private:
    Scheduler(const Scheduler &copy); // Verhindere Kopieren
    Queue readyList;
public:
    void ready(Entrant& that);
    void schedule();
    void exit();
    void kill(Entrant& that);
    void resume();
};

#endif
