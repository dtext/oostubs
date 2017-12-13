
#include <user/appl.h>
#include <thread/scheduler.h>
#include <user/application1.h>
#include <user/application2.h>
#include <device/watch.h>

#define STACK_SIZE 4096

char application_stack[STACK_SIZE];
char my_stack[STACK_SIZE];
char my_other_stack[STACK_SIZE];

int main() {

    Application a(application_stack + STACK_SIZE);
    Application1 myCoroutine(my_stack + STACK_SIZE);
    Application2 myOtherCoroutine(my_other_stack + STACK_SIZE);

    scheduler.ready(a);
    scheduler.ready(myCoroutine);
    scheduler.ready(myOtherCoroutine);

    Watch w(0xffff); // maximum timer length
    w.windup();
    scheduler.schedule();
    return 0;
}

