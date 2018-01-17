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
        coutSemaphore.wait();
        cout << "Foo" << flush;
        cout << "Ende" << flush;
        coutSemaphore.signal();
        keyboard.plugin();
        organizer.exit();
    }
};
