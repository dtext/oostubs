/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I C                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interrupt Controller.                                        */
/* Mit Hilfe des PICs koennen Hardware-Unterbrechungen einzeln zugelassen    */
/* oder unterdrueckt werden. Auf diese Weise wird also bestimmt, ob die      */
/* Unterbrechung eines Geraetes ueberhaupt an den Prozessor weitergegeben    */
/* wird. Selbst dann erfolgt eine Aktivierung der Unterbrechungsroutine nur, */
/* wenn der Prozessor bereit ist, auf Unterbrechungen zu reagieren. Dies     */
/* kann mit Hilfe der Klasse CPU festgelegt werden.                          */
/*****************************************************************************/

/* INCLUDES */

#include "machine/pic.h"
#include "machine/io_port.h"

PIC pic;

void PIC::allow(int interrupt_device) {
    int port_number = interrupt_device < 7 ? 0x21 : 0xA1;
    IO_Port port(port_number);
    int int_mask = port.inb();

    int_mask &= ~(1 << (interrupt_device % 8));
    port.outb(int_mask);
}

void PIC::forbid(int interrupt_device) {
    int port_number = interrupt_device < 7 ? 0x21 : 0xA1;
    IO_Port port(port_number);
    int int_mask = port.inb();
    int_mask |= (1 << (interrupt_device % 8));
    port.outb(int_mask);
}

bool PIC::is_masked(int interrupt_device) {
    int port_number = interrupt_device < 7 ? 0x21 : 0xA1;
    IO_Port port(port_number);
    int int_mask = port.inb();
    return (int_mask >> (interrupt_device % 8)) & 1;
}