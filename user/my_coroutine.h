#include <thread/coroutine.h>
#include <device/cgastr.h>

class MyCoroutine : public Coroutine {
public:
    Coroutine* coroutine;
    MyCoroutine(void* tos, Coroutine* coroutine) : Coroutine(tos) {
        this->coroutine = coroutine;
    }

    void action() override {
        cout << "Foo" << flush;
        //toc_switch(&my_toc, &my_other_toc, 0);
        resume(*coroutine);
        cout << "Ende" << flush;
        while (1) {}
    }
};