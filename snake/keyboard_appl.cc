#include <snake/keyboard_appl.h>
#include <syscall/guarded_keyboard.h>
#include <device/cgastr.h>
#include <syscall/guarded_organizer.h>

void KeyboardApplication::action() {
    while (true) {
        Key pressed = keyboard.getkey();
        if (pressed.ascii() == 'w') {
            snakeData.p1.setDirection(NORTH);
        }else if ((pressed.ascii() == 's')){
            snakeData.p1.setDirection(SOUTH);
        }else if ((pressed.ascii() == 'd')){
            snakeData.p1.setDirection(EAST);
        }else if ((pressed.ascii() == 'a')){
            snakeData.p1.setDirection(WEST);
        }
    }
}