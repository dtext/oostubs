#include <thread/coroutine.h>
#include <device/cgastr.h>

class MyOtherCoroutine : public Coroutine {
public:
    Coroutine* coroutine;
    MyOtherCoroutine(void* tos) : Coroutine(tos) { }

    void setCoroutine(Coroutine* coroutine) {
        this->coroutine = coroutine;
    }

    void action() override {
        cout << "Bar" << flush;
        //toc_switch(&my_other_toc, &my_toc, 0);
        resume(*coroutine);
    }
};