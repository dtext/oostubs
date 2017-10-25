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

void CGA_Screen::show(int x, int y, char c, unsigned char attrib) {
    char *CGA_START = (char *) 0xb8000;
    char *pos;
    pos = CGA_START + 2 * (x + y * 80);
    *pos = c;
    *(pos + 1) = attrib;
}

void CGA_Screen::setpos(int x, int y) {
    IO_Port index_port = IO_Port(0x3d4);
    IO_Port data_port = IO_Port(0x3d5);

    unsigned short cursor_address = x + y * ROW_SIZE;

    index_port.outb(14);
    data_port.outb(cursor_address >> 8);

    index_port.outb(15);
    data_port.outb(cursor_address);
}

void CGA_Screen::getpos(int &x, int &y) {
    IO_Port index_port = IO_Port(0x3d4);
    IO_Port data_port = IO_Port(0x3d5);

    index_port.outb(14);
    int high = data_port.inb();

    index_port.outb(15);
    int low = data_port.inb();

    unsigned short cursor_adress = high << 8 | low;

    x = cursor_adress % ROW_SIZE;
    y = cursor_adress / ROW_SIZE;
}

void CGA_Screen::print(char *text, int length, unsigned char attrib) {
    int x, y;
    getpos(x, y);
    for (int i = 0; i < length; i++) {
        if (*text != '\n') {
            show(x, y, *text, attrib);
            x++;
        }
        //next line
        if (x == ROW_SIZE || *text == '\n') {
            x = 0;
            //scrolling
            if (y + 1 == ROW_COUNT) {
                scroll();
            }
            else {
                y++;
            }
        }
        text++;
    }
    setpos(x, y);
}

void CGA_Screen::get_character(int x, int y, char &c, char &attrib) {
    char *CGA_START = (char *) 0xb8000;
    char *pos;
    pos = CGA_START + 2 * (x + y * 80);
    c = *pos;
    attrib = *(pos + 1);
}

void CGA_Screen::scroll() {
    //move every character one row up
    for (int y = 0; y < ROW_COUNT - 1; y++) {
        for (int x = 0; x < ROW_SIZE; x++) {
            char c, attrib;
            get_character(x, y + 1, c, attrib);
            show(x, y, c, attrib);
        }
    }
    //clear last row
    for (int x = 0; x < ROW_SIZE; x++) {
        show(x, ROW_COUNT - 1, ' ', 15);
    }
}