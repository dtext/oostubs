/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        W A I T I N G R O O M                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Liste von Threads, die auf ein Ereignis warten.                           */
/*****************************************************************************/

#include <syscall/guarded_organizer.h>

Waitingroom::~Waitingroom() {
    Customer *customer;
    while ((customer = (Customer*) Queue::dequeue())) {
        organizer.Organizer::wakeup(*customer);
    }
}

void Waitingroom::remove(Customer *customer) {
    Queue::remove(customer);
}
