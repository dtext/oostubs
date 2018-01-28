//
// Created by julius on 28.01.18.
//
#ifndef OOSTUBS_DATA_H
#define OOSTUBS_DATA_H


#include "machine/cgascr.h"
#include "player.h"

struct SnakeData{
    int field[CGA_Screen::ROW_COUNT][CGA_Screen::ROW_SIZE] = {};
    Player p1 = Player(1,1,SOUTH);
    Player p2 = Player(CGA_Screen::ROW_SIZE-2,CGA_Screen::ROW_COUNT-2,NORTH);
};

extern SnakeData snakeData;


#endif //OOSTUBS_DATA_H
