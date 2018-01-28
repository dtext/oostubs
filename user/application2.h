#include <thread/coroutine.h>
#include <device/cgastr.h>
#include <thread/entrant.h>
#include <snake/data.h>

class Application2 : public Thread {
public:
    Application2(void *tos) : Thread(tos) {}

    void action() override {
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
        organizer.exit();
    }
};