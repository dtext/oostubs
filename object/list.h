/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               L I S T                                     */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung einer einfach verketteten Liste.                          */
/*****************************************************************************/

#ifndef __List_include__
#define __List_include__

#include "object/queue.h"

class List : public Queue {
private:
    List(const List &copy); // Verhindere Kopieren

public:
    List() {}

    // Liefert das erste Element der Liste
    Chain *first() { return head; }

    // INSERT_FIRST: Stellt das Element an den Anfang der Liste
    void insert_first(Chain *new_item);

    // INSERT_AFTER: Fuegt das neue Element hinter dem angegebenen alten
    //               Element in die Liste ein.
    void insert_after(Chain *old_item, Chain *new_item);
};

#endif

