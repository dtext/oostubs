//
// Created by julius on 28.01.18.
//

#ifndef OOSTUBS_KEYBOARD_APPL_H
#define OOSTUBS_KEYBOARD_APPL_H

#include <user/appl.h>
#include <snake/data.h>

class KeyboardApplication : public Application {
public:
    KeyboardApplication(void *tos) : Application(tos) {}
    void action() override;
};

#endif //OOSTUBS_KEYBOARD_APPL_H
