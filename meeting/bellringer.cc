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
    auto *bell = (Bell *) List::head;
    // tick first bell upon check
    if (bell != nullptr) {
        bell->tick();
    }
    // ring all bells that are run down
    while (bell && bell->run_down()) {
        bell->ring();
        bell = (Bell *) bell->next;
    }
    // remove all bells that were rung
    List::head = bell;
    if (List::head == nullptr)
        List::tail = &head;
}

void Bellringer::job(Bell *bell, int ticks) {
    int tick_count = 0;
    // find list position for new job
    auto *listed = (Bell *) List::head;
    while (listed && tick_count + listed->wait() < ticks) {
        tick_count += listed->wait();
        listed = (Bell *) listed->next;
    }
    // delta encode wait time
    bell->wait(ticks - tick_count);

    // if new job is first bell to be rung, insert at beginning
    if (listed == nullptr) {
        insert_first(bell);
        return;
    }
    // otherwise insert at position
    insert_after(listed, bell);
}

void Bellringer::cancel(Bell *bell) {
    auto *next = (Bell *) bell->next;
    // if theres another item in the queue, add this job's timer value to theirs
    if (next != nullptr) {
        next->wait(next->wait() + bell->wait());
    }
    // then just remove the job
    Queue::remove(bell);
}
