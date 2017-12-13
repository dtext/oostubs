
#include <user/appl.h>
#include <thread/scheduler.h>
#include <user/application1.h>
#include <user/application2.h>
#include <device/watch.h>
#include <guard/guard.h>

#define STACK_SIZE 4096

char application_stack[STACK_SIZE];
char my_stack[STACK_SIZE];
char my_other_stack[STACK_SIZE];

int main() {

    guard.enter();
    Application a(application_stack + STACK_SIZE);
    Application1 myCoroutine(my_stack + STACK_SIZE);
    Application2 myOtherCoroutine(my_other_stack + STACK_SIZE);

    scheduler.Scheduler::ready(a);
    scheduler.Scheduler::ready(myCoroutine);
    scheduler.Scheduler::ready(myOtherCoroutine);

    Watch w(0xFFFF); // maximum timer length
    w.windup();
    scheduler.schedule();
    return 0;
}

