/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Q U E U E                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung einer einfach verketteten Liste von Chain Objekten.       */
/* enqueue fuegt ein neues Element an das Ende der Liste an.                 */
/* dequeue entfernt das erste und remove das angegebene Element der Liste.   */
/* Initial ist die Liste leer.                                               */
/*****************************************************************************/

#ifndef __queue_include__
#define __queue_include__

#include "object/chain.h"

class Queue
 {
private:
      Queue(const Queue &copy); // Verhindere Kopieren

protected:
      Chain* head;
      Chain** tail;

public:
      Queue () { head = 0; tail = &head; }
      void enqueue (Chain* item);
      Chain* dequeue ();
      void remove (Chain*);
 };

#endif

