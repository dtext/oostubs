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
    Bell *listed = (Bell *) Queue::head;
    if (!listed || listed->wait() > ticks) {
        // no beĺl in list or first wait time already higher
        bell->wait(ticks);
        insert_first(bell);
        // update following element if need be
        listed = (Bell *) bell->next;
        if (listed) {
            listed->wait(listed->wait() - ticks);
        }
        return;
    }

    Bell* last = 0;

    // find list position for new job
    while (listed && listed->wait() <= ticks) {
        ticks -= listed->wait();
        last = listed;
        listed = (Bell *) listed->next;
    }

    bell->wait(ticks);
    if (!listed) {
        Queue::enqueue(bell);
        return;
    }

    listed->wait(listed->wait() - ticks);
    insert_after(last, bell);
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
