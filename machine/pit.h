/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

#ifndef __pit_include__
#define __pit_include__

#include "io_port.h"

class PIT {
private:
    PIT(const PIT &copy); // Verhindere Kopieren
    int interval_us;
    IO_Port control_port = IO_Port(0x43);
    IO_Port data_port = IO_Port(0x40);
public:
    PIT(int us) {
        interval(us);
    }

    int interval() {
        return interval_us;
    }

    void interval(int us);
};

#endif
