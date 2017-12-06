#include <thread/coroutine.h>
#include <device/cgastr.h>
#include <thread/entrant.h>
#include <thread/scheduler.h>

class Application1 : public Entrant {
public:
    Application1(void *tos) : Entrant(tos) {
    }

    void action() override {
        cout << "Foo" << flush;
        scheduler.resume();
        cout << "Ende" << flush;
        scheduler.exit();
    }
};
