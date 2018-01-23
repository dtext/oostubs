#include <thread/coroutine.h>
#include <device/cgastr.h>
#include <thread/entrant.h>
#include <meeting/bell.h>
#include <meeting/bellringer.h>
#include <guard/secure.h>

class MyJob : public Bell {
public:
    void ring() {
        cout << "Ringading" << flush;
    }
};

class Application2 : public Thread {
public:
    Application2(void *tos) : Thread(tos) {}
    MyJob job;
    MyJob job2;
    MyJob job3;
    MyJob job4;

    void action() override {
        {
            Secure secure;
            bellringer.job(&job, 10000);
            bellringer.dump();
            bellringer.job(&job2, 10000);
            bellringer.dump();
            bellringer.job(&job3, 10000);
            bellringer.dump();
            bellringer.job(&job4, 10000);
            bellringer.dump();
        }
        coutSemaphore.wait();
        cout << "Bar" << flush;
        coutSemaphore.signal();
        organizer.exit();
    }
};