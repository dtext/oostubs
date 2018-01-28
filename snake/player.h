//
// Created by julius on 28.01.18.
//

#ifndef OOSTUBS_PLAYER_H
#define OOSTUBS_PLAYER_H

enum Direction{
    NORTH,SOUTH,EAST,WEST
};

class Player {
private:
    int id;
    int x;
    int y;
    Direction direction;

public:
    Player(int x, int y, Direction direction) : x(x),y(y),direction(direction){};
    void move(){
        switch(direction){
            case NORTH:
                y--;
                break;
            case SOUTH:
                y++;
                break;
            case EAST:
                x++;
                break;
            case WEST:
                x--;
                break;
        }
    }
    int getX(){return x;}
    int getY(){return y;}
    void setDirection(Direction dir){
         direction=dir;
    }
};

#endif //OOSTUBS_PLAYER_H
