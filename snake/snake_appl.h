//
// Created by julius on 28.01.18.
//

#ifndef OOSTUBS_SNAKE_APPL_H
#define OOSTUBS_SNAKE_APPL_H

#include <user/appl.h>
#include <snake/data.h>

class SnakeApplication : public Application {
public:
    SnakeApplication(void *tos) : Application(tos) {}

    void printBorder();

    void printMessage(char *msg);

    void action() override;

    bool isOutOfField(Player player);

    bool collides(Player player);
};

#endif //OOSTUBS_SNAKE_APPL_H
