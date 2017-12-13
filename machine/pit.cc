/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

#include "pit.h"

/* Hier muesst ihr selbst Code vervollstaendigen */
void PIT::interval(int us) {
    interval_us = us;
    // 00:Counter 0; 11:lower then higher byte; 010:periodic interrupts; 0:binary counting
    control_port.outb(0b00110100);
    char lower = us;
    char higher = us << 8;
    data_port.outb(lower);
    data_port.outb(higher);
}
