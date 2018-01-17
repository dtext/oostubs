/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          B E L L R I N G E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Der "Gloeckner" wird im Rahmen der Timer-Epilog Bearbeitung aktiviert.    */
/* Er prueft, ob irgendwelche Glocken (Bell-Objekte) laeuten muessen. Die    */
/* Glocken befinden sich in einer Queue, die der Gloeckner verwaltet.        */
/*****************************************************************************/

#include "bellringer.h"

Bellringer bellringer;

void Bellringer::check() {
    Bell *bell = (Bell *) List::head;
    // tick first bell upon check
    if (bell != 0) {
        bell->tick();
    }
    // ring all bells that are run down
    while (bell && bell->run_down()) {
        bell->ring();
        bell = (Bell *) bell->next;
    }
    // remove all bells that were rung
    List::head = bell;
    if (List::head == 0)
        List::tail = &head;
}

void Bellringer::job(Bell *bell, int ticks) {
    int tick_count = 0;
    // find list position for new job
    Bell *listed = (Bell *) List::head;
    while (listed && tick_count + listed->wait() < ticks) {
        tick_count += listed->wait();
        listed = (Bell *) listed->next;
    }
    // delta encode wait time
    bell->wait(ticks - tick_count);

    // if new job is first bell to be rung, insert at beginning
    if (listed == 0) {
        insert_first(bell);
        return;
    }
    // otherwise insert at position
    insert_after(listed, bell);
}

void Bellringer::cancel(Bell *bell) {
    Bell *next = (Bell *) bell->next;
    // if theres another item in the queue, add this job's timer value to theirs
    if (next != 0) {
        next->wait(next->wait() + bell->wait());
    }
    // then just remove the job
    Queue::remove(bell);
}
