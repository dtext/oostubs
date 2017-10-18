#include "machine/cgascr.h"

#include "device/cgastr.h"

int main() {

    CGA_Stream cga_stream;
    cga_stream.setpos(0, 0);
    cga_stream << (int) 2109348 << (char) ' ' << 123;
    cga_stream.flush();

    return 0;
}
