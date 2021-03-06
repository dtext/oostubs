/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          O R G A N I Z E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Ein Organizer ist ein spezieller Scheduler, der zusaetzlich das Warten    */
/* von Threads (Customer) auf Ereignisse erlaubt.                            */
/*****************************************************************************/

#include <thread/organizer.h>
#include <meeting/waitingroom.h>

void Organizer::block(Customer &customer, Waitingroom &waitingroom) {
    waitingroom.enqueue(&customer);
    customer.waiting_in(&waitingroom);
    exit();
}

void Organizer::wakeup(Customer &customer) {
    customer.waiting_in(0);
    ready(customer);
}

void Organizer::kill(Customer &that) {
    Waitingroom *w = that.waiting_in();
    if (w != 0) {
        w->remove(&that);
    }else{
        Scheduler::kill(that);
    }

}