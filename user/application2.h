#include <thread/coroutine.h>
#include <device/cgastr.h>
#include <thread/entrant.h>
#include <thread/scheduler.h>

class Application2 : public Entrant {
public:
    Application2(void *tos) : Entrant(tos) {}

    void action() override {
        cout << "Bar" << flush;
        scheduler.exit();
    }
};