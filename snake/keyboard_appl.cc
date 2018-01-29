#include <snake/keyboard_appl.h>
#include <syscall/guarded_keyboard.h>
#include <device/cgastr.h>
#include <syscall/guarded_organizer.h>

void KeyboardApplication::action() {
    while (true) {
        Key pressed = keyboard.getkey();
        gameDataSemaphore.wait();
        if (pressed.ascii() == 'w') {
            snakeData.p1.setDirection(NORTH);
        }else if (pressed.ascii() == 's'){
            snakeData.p1.setDirection(SOUTH);
        }else if (pressed.ascii() == 'd'){
            snakeData.p1.setDirection(EAST);
        }else if (pressed.ascii() == 'a'){
            snakeData.p1.setDirection(WEST);
        }else if(pressed.scancode() == 0x48){
            snakeData.p2.setDirection(NORTH);
        }else if(pressed.scancode() == 0x50){
            snakeData.p2.setDirection(SOUTH);
        }else if(pressed.scancode() == 0x4d){
            snakeData.p2.setDirection(EAST);
        }else if(pressed.scancode() == 0x4b){
            snakeData.p2.setDirection(WEST);
        }
        gameDataSemaphore.signal();
    }
}