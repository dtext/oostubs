/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           S E M A P H O R E                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Semaphore werden zur Synchronisation von Threads verwendet.               */
/*****************************************************************************/

#include <syscall/guarded_scheduler.h>
#include <syscall/guarded_organizer.h>
#include "meeting/semaphore.h"

Semaphore::Semaphore(int c) {
    this->c = c;
}

void Semaphore::p() {
    if (this->c > 0) {
        c--;
    } else {
        Customer *customer = (Customer *) organizer.active();
        organizer.Organizer::block(*customer, *this);
    }
}

void Semaphore::v() {
    if (head) {
        Customer *customer = (Customer *) dequeue();
        organizer.Organizer::wakeup(*customer);
    } else {
        c++;
    }
}
