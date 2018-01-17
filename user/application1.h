#include <thread/coroutine.h>
#include <device/cgastr.h>
#include <thread/entrant.h>
#include <syscall/guarded_organizer.h>
#include <syscall/guarded_keyboard.h>

class Application1 : public Thread {
public:
    Application1(void *tos) : Thread(tos) {
    }

    void action() override {
        cout << "Foo" << flush;
        cout << "Ende" << flush;

        keyboard.plugin();

        while (true) {
            Key pressed = keyboard.getkey();
            cout << pressed.ascii() << flush;
        }

        organizer.exit();
    }
};
