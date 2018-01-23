#include <thread/coroutine.h>
#include <device/cgastr.h>
#include <thread/entrant.h>
#include <syscall/guarded_organizer.h>
#include <syscall/guarded_keyboard.h>
#include <syscall/guarded_buzzer.h>

class Application1 : public Thread {
public:
    Application1(void *tos) : Thread(tos) {
    }

    void action() override {
        //unsigned int max_value = 10000;
        //while (true) {
        //    Guarded_Buzzer buzzer;
        //    buzzer.set(max_value);
        //    buzzer.sleep();
        //    coutSemaphore.wait();
        //    cout << "Foo" << flush;
        //    cout << "Ende" << flush;
        //    coutSemaphore.signal();
        //}
        keyboard.plugin();
        organizer.exit();
    }
};
