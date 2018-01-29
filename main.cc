
#include <user/appl.h>
#include <thread/scheduler.h>
#include <user/application1.h>
#include <user/application2.h>
#include <device/watch.h>
#include <guard/guard.h>
#include <snake/snake_appl.h>
#include <snake/keyboard_appl.h>

#define STACK_SIZE 4096

char application_stack[STACK_SIZE];
char my_stack[STACK_SIZE];
char my_other_stack[STACK_SIZE];

int main() {

    guard.enter();
    SnakeApplication snakeApp(application_stack + STACK_SIZE);
    KeyboardApplication keyboardApp(my_stack + STACK_SIZE);

    organizer.Scheduler::ready(snakeApp);
    organizer.Scheduler::ready(keyboardApp);

    Watch w(0x00FF); // set timer length
    w.windup();
    keyboard.plugin();
    organizer.schedule();
    return 0;
}

