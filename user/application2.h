#include <thread/coroutine.h>
#include <device/cgastr.h>
#include <thread/entrant.h>
#include <meeting/bell.h>
#include <meeting/bellringer.h>
#include <guard/secure.h>

class MyJob : public Bell {
private:
    char *name;
public:
    MyJob() {}

    void setName(char *name) {
        this->name = name;
    }

    void ring() {
        cout << "Job \"" << name << "\" has finished." << endl << flush;
    }
};

class Application2 : public Thread {
public:
    Application2(void *tos) : Thread(tos) {}

    MyJob job1;
    MyJob job2;
    MyJob job3;
    MyJob job4;

    void action() override {
        job1.setName("#1");
        job2.setName("#2");
        job3.setName("#3");
        job4.setName("#4");
        {
            Secure secure;
            bellringer.job(&job1, 5000);
            bellringer.job(&job2, 10000);
            bellringer.job(&job3, 20000);
            bellringer.job(&job4, 15000);
        }
        coutSemaphore.wait();
        cout << "Bar" << flush;
        coutSemaphore.signal();
        organizer.exit();
    }
};