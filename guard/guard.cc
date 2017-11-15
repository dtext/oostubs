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
#include "machine/cpu.h"
#include "device/cgastr.h"

Guard guard;

void Guard::leave() {
    /*
     * This ugly while loop is responsible for the case where the last epilogue is handled,
     * making g == NULL. If another interrupt occurs after the while loop is exited, but
     * before locked is set to false, that new interrupt will be enqueued but its epilogue
     * will be left unhandled.
     */
    cpu.disable_int();
    Gate *g = (Gate *) q.dequeue();
    while (1) {
        cpu.disable_int();
        if (g == 0) {
            retne();
            cpu.enable_int();
            break;
        }
        cpu.enable_int();

        g->epilogue();

        cpu.disable_int();
        g = (Gate *) q.dequeue();
        cpu.enable_int();

    }
}

void Guard::relay(Gate *gate) {
    cpu.disable_int();
    if (avail()) {
        enter();
        cpu.enable_int();
        gate->epilogue();
        leave();
    } else {
        q.enqueue(gate);
        cpu.enable_int();
    }
}