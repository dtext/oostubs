/* $Id$ */

/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             C G A _ S C R E E N                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe dieser Klasse kann man auf den Bildschirm des PCs zugreifen.    */
/* Der Zugriff erfolgt direkt auf der Hardwareebene, d.h. ueber den Bild-    */
/* schirmspeicher bzw. die I/O-Ports der Grafikkarte.                        */
/*****************************************************************************/

#include "machine/cgascr.h"
#include "machine/io_port.h"

/* Hier muesst ihr selbst Code vervollstaendigen */
void CGA_Screen::show (int x, int y, char c, unsigned char attrib){
    char *CGA_START = (char *)0xb8000;
    char *pos;
    pos = CGA_START + 2*(x + y*80);
    *pos = c;
    *(pos + 1) = attrib;
}

void CGA_Screen::setpos (int x, int y){
    IO_Port index_port = IO_Port(0x3d4);
    IO_Port data_port = IO_Port(0x3d5);

    index_port.outb(15);
    data_port.outb(x);

    index_port.outb(14);
    data_port.outb(y);
}

void CGA_Screen::getpos(int &x, int &y){
    IO_Port index_port = IO_Port(0x3d4);
    IO_Port data_port = IO_Port(0x3d5);

    index_port.outb(15);
    x = data_port.inb();

    index_port.outb(14);
    y = data_port.inb();
}

void CGA_Screen::print(char* text, int length, unsigned char attrib){
    int x,y;
    getpos(x,y);
    for(int i=0;i<length;i++){
        show(x,y,*text,attrib);
        text++;
        x++;
    }
    setpos(x,y);
}