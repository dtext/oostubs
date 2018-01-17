/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               B U Z Z E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe des "Weckers" koennen Prozesse eine bestimmte Zeit lang         */
/* schlafen und sich dann wecken lassen.                                     */
/*****************************************************************************/

#ifndef __Buzzer_include__
#define __Buzzer_include__

#include "bell.h"
#include "waitingroom.h"

class Buzzer : public Bell, public Waitingroom {
private:
    Buzzer(const Buzzer &copy); // Verhindere Kopieren

    int ms;

protected:
    void destructor();

public:
    Buzzer() {
        ms = 0;
    }

    virtual ~Buzzer();

    virtual void ring();

    void set(int ms);

    void sleep();
};

#endif
