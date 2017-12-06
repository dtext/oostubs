/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                G U A R D                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe dieser Klasse koennen Aktivitaeten, die einen kritischen        */
/* Abschnitt betreffen, der mit einem Guard-Objekt geschuetzt ist, mit       */
/* Unterbrechungsbehandlungsroutinen synchronisiert werden, die ebenfalls    */
/* auf den kritischen Abschnitt zugreifen.                                   */
/*****************************************************************************/

#include "guard/guard.h"

Guard guard;

void Guard::leave() {
    /*
     * This pretty while loop is responsible for the case where the last epilogue is handled,
     * making g == NULL. If another interrupt occurs after the while loop is exited, but
     * before locked is set to false, that new interrupt will be enqueued but its epilogue
     * will be left unhandled.
     */
    Gate *g;
    while (1) {
        cpu.disable_int();
        g = (Gate *) q.dequeue();;
        if (g == 0) {
            retne();
            cpu.enable_int();
            break;
        }
        g->queued(false);
        cpu.enable_int();

        g->epilogue();
    }
}

void Guard::relay(Gate *gate) {
    if (avail()) {
        enter();
        gate->epilogue();
        leave();
    } else if (!gate->queued()) {
        q.enqueue(gate);
        gate->queued(true);
    }
}