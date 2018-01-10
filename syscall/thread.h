/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             T H R E A D                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Benutzerschnittstelle eines Threads.                                      */
/*****************************************************************************/

#ifndef __thread_include__
#define __thread_include__

#include "thread/customer.h"

class Thread : public Customer {
public:
    Thread(void *tos) : Customer(tos) {};
private:
    Thread(const Thread &copy); // Verhindere Kopieren

};

#endif
