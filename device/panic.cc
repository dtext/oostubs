/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Standard Unterbrechungsbehandlung.                                        */
/*****************************************************************************/
/* Hier muesst ihr selbst Code vervollstaendigen */
/* Hier muesst ihr selbst Code vervollstaendigen */

/* INCLUDES */

#define MARGIN_LEFT 7
#define MARGIN_RIGHT (80 - MARGIN_LEFT)


#include "device/panic.h"
#include "device/cgastr.h"
#include "machine/cpu.h"

Panic panic;

int getErrorLength(char *error) {
    int i;
    for (i = 0; error[i]; i++);
    return i;
}

bool Panic::prologue() {
    for (int i = 0; i < 2000; i++)
        cout.show(i, 0, ' ', 1 << 4);
    int marginTop = 3;
    cout.setpos(MARGIN_LEFT, marginTop++);
    cout.print("      __", 9, 1 << 4 | 15);
    cout.setpos(MARGIN_LEFT, marginTop++);
    cout.print(" _   / /", 9, 1 << 4 | 15);
    cout.setpos(MARGIN_LEFT, marginTop++);
    cout.print("(_) | | ", 9, 1 << 4 | 15);
    cout.setpos(MARGIN_LEFT, marginTop++);
    cout.print(" _  | | ", 9, 1 << 4 | 15);
    cout.setpos(MARGIN_LEFT, marginTop++);
    cout.print("(_) | | ", 9, 1 << 4 | 15);
    cout.setpos(MARGIN_LEFT, marginTop++);
    cout.print("     \\_\\", 9, 1 << 4 | 15);
    cout.setpos(MARGIN_LEFT, marginTop += 2);
    cout.print("Kernel Panic!", 15, 1 << 4 | 15);
    cout.setpos(MARGIN_LEFT, ++marginTop);

    // Prints error message
    int x, y;
    for (int i = 0; error[i]; i++) {
        if (i != 0 && !(i % MARGIN_RIGHT))
            cout.setpos(MARGIN_LEFT, ++marginTop);
        cout.getpos(x, y);
        cout.show(x, y, error[i], 1 << 4 | 15);
        cout.setpos(++x, y);
    }
    cpu.halt();
    return false; // this is here to avoid compiler errors
}


