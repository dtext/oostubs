
#include <user/appl.h>
#include <thread/scheduler.h>
#include <user/application1.h>
#include <user/application2.h>
#include <device/watch.h>
#include <guard/guard.h>
#include <syscall/guarded_organizer.h>

#define STACK_SIZE 4096

char application_stack[STACK_SIZE];
char my_stack[STACK_SIZE];
char my_other_stack[STACK_SIZE];

int main() {

    guard.enter();
    Application a(application_stack + STACK_SIZE);
    Application1 myCoroutine(my_stack + STACK_SIZE);
    Application2 myOtherCoroutine(my_other_stack + STACK_SIZE);

    organizer.Scheduler::ready(a);
    organizer.Scheduler::ready(myCoroutine);
    organizer.Scheduler::ready(myOtherCoroutine);

    Watch w(0xFFFF); // maximum timer length
    w.windup();
    organizer.schedule();
    return 0;
}

