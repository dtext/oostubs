#include <thread/coroutine.h>
#include <device/cgastr.h>
#include <thread/entrant.h>
#include <syscall/guarded_scheduler.h>

class Application1 : public Thread {
public:
    Application1(void *tos) : Thread(tos) {
    }

    void action() override {
        cout << "Foo" << flush;
        cout << "Ende" << flush;
        scheduler.exit();
    }
};
