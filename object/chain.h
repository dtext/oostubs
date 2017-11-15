/* $Id$ */

/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              C H A I N                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Verkettungszeiger zum Einfuegen eines Objektes in eine einfach verkettete */
/* Liste.                                                                    */
/*****************************************************************************/

#ifndef __chain_include__
#define __chain_include__

class Chain
 {
private:
      Chain(const Chain &copy); // Verhindere Kopieren

public:
      Chain() {}
      Chain* next;
 };

#endif

