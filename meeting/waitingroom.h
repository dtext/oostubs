/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        W A I T I N G R O O M                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Liste von Threads, die auf ein Ereignis warten.                           */
/*****************************************************************************/

#ifndef __waitingroom_include__
#define __waitingroom_include__

#include "object/queue.h"

class Customer;

class Waitingroom : public Queue {
private:
    Waitingroom(const Waitingroom &copy);

public:
    Waitingroom() {}

    virtual ~Waitingroom();

    virtual void remove(Customer *customer);

};

#endif
