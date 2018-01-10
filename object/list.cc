/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               L I S T                                     */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung einer einfach verketteten Liste.                          */
/*****************************************************************************/

#include "object/list.h"

// INSERT_FIRST: Stellt das Element an den Anfang der Liste
void List::insert_first(Chain *new_item) {
    if (head)   // Die Liste ist nicht leer.
    {
        new_item->next = head;
        head = new_item;
    } else       // Die Liste ist leer. Dann kann das Element genausogut
    {         // hinten angehaengt werden.
        enqueue(new_item);
    }
}

// INSERT_AFTER: Fuegt das neue Element hinter dem angegebenen alten
//               Element in die Liste ein.
void List::insert_after(Chain *old_item, Chain *new_item) {
    new_item->next = old_item->next;
    old_item->next = new_item;
}
