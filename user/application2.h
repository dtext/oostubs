#include <thread/coroutine.h>
#include <device/cgastr.h>
#include <thread/entrant.h>

class Application2 : public Thread {
public:
    Application2(void *tos) : Thread(tos) {}

    void action() override {
        cout << "Bar" << flush;
        scheduler.exit();
    }
};