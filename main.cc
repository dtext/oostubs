
#include <user/appl.h>
#include <thread/scheduler.h>
#include <user/application1.h>
#include <user/application2.h>

char application_stack[4096];
char my_stack[4096];
char my_other_stack[4096];

int main() {

    Application a(application_stack + 4096);
    scheduler.ready(a);
    Application1 myCoroutine(my_stack + 4096);
    Application2 myOtherCoroutine(my_other_stack + 4096);
    scheduler.ready(myCoroutine);
    scheduler.ready(myOtherCoroutine);
    scheduler.schedule();
    return 0;
}

