#include <thread/coroutine.h>
#include <device/cgastr.h>
#include <thread/entrant.h>
#include <meeting/bell.h>
#include <meeting/bellringer.h>

class MyJob : public Bell {
public:
    void ring() {
        cout << "Ringading" << flush;
    }
};

class Application2 : public Thread {
public:
    Application2(void *tos) : Thread(tos) {}

    void action() override {
        MyJob job;
        bellringer.job(&job, 0);
        coutSemaphore.wait();
        cout << "Bar" << flush;
        coutSemaphore.signal();
        organizer.exit();
    }
};