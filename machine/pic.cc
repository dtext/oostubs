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
#include "machine/cpu.h"
#include "machine/io_port.h"
#include "device/cgastr.h"

void PIC::allow(int interrupt_device){
    CPU cpu;
    cpu.enable_int();
    IO_Port port(0x21);
    int int_mask = port.inb();
    int_mask &= (1 << (interrupt_device-1));
    port.outb(int_mask);
}

void PIC::forbid(int interrupt_device){
    IO_Port port(0x21);
    int int_mask = port.inb();
    int_mask |= ~(1 << (interrupt_device-1));
    port.outb(int_mask);
}