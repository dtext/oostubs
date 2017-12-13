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

class PIT
 {
private:
    PIT(const PIT &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */ 
public:
    PIT (int us) {
      interval (us);
    }
    int interval () {
/* Hier muesst ihr selbst Code vervollstaendigen */ 
    }
    void interval (int us);
};

#endif
