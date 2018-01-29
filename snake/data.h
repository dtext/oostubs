//
// Created by julius on 28.01.18.
//
#ifndef OOSTUBS_DATA_H
#define OOSTUBS_DATA_H


#include "machine/cgascr.h"
#include "player.h"

class SnakeData{
public:
    int field[CGA_Screen::ROW_COUNT][CGA_Screen::ROW_SIZE] = {};
    Player p1 = Player(1,1,SOUTH,3 << 4 | 15);
    Player p2 = Player(CGA_Screen::ROW_SIZE-2,CGA_Screen::ROW_COUNT-2,NORTH,6 << 4 | 15);
    void reset(){
        for(int i=0;i<CGA_Screen::ROW_COUNT;i++){
            for(int j=0;j<CGA_Screen::ROW_SIZE;j++){
                field[i][j] = 0;
            }
        }
        p1 = Player(1,1,SOUTH,3 << 4 | 15);
        p2 = Player(CGA_Screen::ROW_SIZE-2,CGA_Screen::ROW_COUNT-2,NORTH,6 << 4 | 15);
    }
};

extern SnakeData snakeData;
extern Guarded_Semaphore gameDataSemaphore;


#endif //OOSTUBS_DATA_H
