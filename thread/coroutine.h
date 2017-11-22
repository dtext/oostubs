/* $Id$ */

/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          C O R O U T I N E                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Koroutinenkonzepts.                                   */
/* Im Konstruktor wird der initialie Kontext der Koroutine eingerichtet.     */
/* Mit go() wird die erste Koroutine aktiviert. Alle weiteren                */
/* Koroutinenwechsel sollten mit resume() erfolgen.                          */
/* Um bei einem Koroutinenwechsel den Kontext sichern zu koennen, enthaelt   */
/* jedes Koroutinenobjekt eine Struktur toc, in dem die Werte der nicht-     */
/* fluechtigen Register gesichert werden koennen.                            */
/*****************************************************************************/

#ifndef __Coroutine_include__
#define __Coroutine_include__

#include "machine/toc.h"

class Coroutine
 {
private:
      Coroutine(const Coroutine &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */     
 };

#endif
