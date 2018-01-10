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
#include "thread/customer.h"

class Customer; // Forward declaration

class Waitingroom
        : public Queue {
private:
    Waitingroom(const Waitingroom &copy); // Verhindere Kopieren
public:
    Waitingroom() {}
/* Hier muesst ihr selbst Code vervollstaendigen */
};

#endif
