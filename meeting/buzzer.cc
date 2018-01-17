/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               B U Z Z E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe des "Weckers" koennen Prozesse eine bestimmte Zeit lang         */
/* schlafen und sich dann wecken lassen.                                     */
/*****************************************************************************/

#include <syscall/guarded_organizer.h>
#include "buzzer.h"
#include "bellringer.h"

Buzzer::~Buzzer() {
    destructor();
}

void Buzzer::ring() {
    Customer *customer = (Customer *) dequeue();
    organizer.Organizer::wakeup(*customer);
}

void Buzzer::set(int ms) {
    this->ms = ms;
}

void Buzzer::sleep() {
    bellringer.job(this, ms);
    Customer *customer = (Customer *) organizer.active();
    organizer.Organizer::block(*customer, *this);
}

void Buzzer::destructor() {
    bellringer.cancel(this);

    Customer *customer;
    while (customer = (Customer *) dequeue()) {
        organizer.Organizer::wakeup(*customer);
    }
}