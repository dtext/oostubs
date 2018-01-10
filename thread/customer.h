/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         C U S T O M E R                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Ein Thread, der auf ein Ereignis warten kann.                             */
/*****************************************************************************/

#ifndef __customer_include__
#define __customer_include__

#include <thread/entrant.h>
#include <meeting/waitingroom.h>

/* Hier muesst ihr selbst Code vervollstaendigen */

class Customer : public Entrant {

private:
    Customer(const Customer &copy); // Verhindere Kopieren
    Waitingroom *waiting_room;

public:
    Customer(void *tos) : Entrant(tos) {};

    void waiting_in(Waitingroom *w) { waiting_room = w; };

    Waitingroom *waiting_in() { return waiting_room; }
};

#endif
