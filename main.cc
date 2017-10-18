#include "machine/cgascr.h"

int main()
{
    CGA_Screen cga_screen;
    cga_screen.show(0,0,'X',0x0f);
    return 0;
 }
