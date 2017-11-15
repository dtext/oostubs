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

#ifndef __Guard_include__
#define __Guard_include__

/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
class Guard : public Locker
 {
private:
    Guard (const Guard &copy); // Verhindere Kopieren
public:
    Guard () {}
/* Hier muesst ihr selbst Code vervollstaendigen */          
 };

#endif
