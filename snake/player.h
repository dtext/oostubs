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
    int x;
    int y;
    Direction direction;
    unsigned char style;

public:
    Player(int x, int y, Direction direction, unsigned char style) : x(x),y(y),direction(direction),style(style){};
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
    unsigned char getStyle(){return style;}
    void setDirection(Direction dir){
        switch(dir){
            case NORTH:
                if(direction == SOUTH) return;
                break;
            case SOUTH:
                if(direction == NORTH) return;
                break;
            case EAST:
                if(direction == WEST) return;
                break;
            case WEST:
                if(direction == EAST) return;
                break;
        }
        direction=dir;
    }
};

#endif //OOSTUBS_PLAYER_H
