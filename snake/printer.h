//
// Created by julius on 29.01.18.
//

#ifndef OOSTUBS_PRINTER_H
#define OOSTUBS_PRINTER_H

int p1_top_margin = 5;
int p1_left_margin = 20;
int p2_top_margin = p1_top_margin+6;
int p2_left_margin = p1_left_margin;

void printL(int left, int top, unsigned char style){
    cout.show(left,top, ' ',style);
    cout.show(left,top+1, ' ',style);
    cout.show(left,top+2, ' ',style);
    cout.show(left,top+3, ' ',style);
    cout.show(left,top+4, ' ',style);
    cout.show(left+1,top, ' ',style);
    cout.show(left+1,top+1, ' ',style);
    cout.show(left+1,top+2, ' ',style);
    cout.show(left+1,top+3, ' ',style);
    cout.show(left+1,top+4, ' ',style);
    cout.show(left+2,top+4, ' ',style);
    cout.show(left+3,top+4, ' ',style);
}

void printO(int left, int top, unsigned char style){
    cout.show(left+1,top, ' ',style);
    cout.show(left,top, ' ',style);
    cout.show(left,top+1, ' ',style);
    cout.show(left,top+2, ' ',style);
    cout.show(left,top+3, ' ',style);
    cout.show(left,top+4, ' ',style);
    cout.show(left+1,top+4, ' ',style);
    cout.show(left+2,top, ' ',style);
    cout.show(left+3,top, ' ',style);
    cout.show(left+3,top+1, ' ',style);
    cout.show(left+3,top+2, ' ',style);
    cout.show(left+3,top+3, ' ',style);
    cout.show(left+3,top+4, ' ',style);
    cout.show(left+2,top+4, ' ',style);
}

void printS(int left, int top, unsigned char style){
    cout.show(left,top,' ',style);
    cout.show(left+1,top,' ',style);
    cout.show(left+2,top,' ',style);
    cout.show(left+3,top,' ',style);
    cout.show(left,top+1,' ',style);
    cout.show(left,top+2,' ',style);
    cout.show(left+1,top+2,' ',style);
    cout.show(left+2,top+2,' ',style);
    cout.show(left+3,top+2,' ',style);
    cout.show(left+3,top+3,' ',style);
    cout.show(left+3,top+4,' ',style);
    cout.show(left+2,top+4,' ',style);
    cout.show(left+1,top+4,' ',style);
    cout.show(left,top+4,' ',style);
}

void printE(int left, int top, unsigned char style){
    cout.show(left,top,' ',style);
    cout.show(left+1,top,' ',style);
    cout.show(left+2,top,' ',style);
    cout.show(left+3,top,' ',style);
    cout.show(left,top+1,' ',style);
    cout.show(left,top+2,' ',style);
    cout.show(left+1,top+2,' ',style);
    cout.show(left+2,top+2,' ',style);
    cout.show(left+3,top+2,' ',style);
    cout.show(left,top+3,' ',style);
    cout.show(left,top+4,' ',style);
    cout.show(left+1,top+4,' ',style);
    cout.show(left+2,top+4,' ',style);
    cout.show(left+3,top+4,' ',style);
}

void printW(int left, int top, unsigned char style){
    cout.show(left,top,' ',style);
    cout.show(left,top+1,' ',style);
    cout.show(left,top+2,' ',style);
    cout.show(left,top+3,' ',style);
    cout.show(left,top+4,' ',style);
    cout.show(left+4,top,' ',style);
    cout.show(left+4,top+1,' ',style);
    cout.show(left+4,top+2,' ',style);
    cout.show(left+4,top+3,' ',style);
    cout.show(left+4,top+4,' ',style);
    cout.show(left+1,top+3,' ',style);
    cout.show(left+2,top+2,' ',style);
    cout.show(left+3,top+3,' ',style);
}

void printI(int left, int top, unsigned char style){
    cout.show(left,top,' ',style);
    cout.show(left,top+1,' ',style);
    cout.show(left,top+2,' ',style);
    cout.show(left,top+3,' ',style);
    cout.show(left,top+4,' ',style);
    cout.show(left+1,top,' ',style);
    cout.show(left+1,top+1,' ',style);
    cout.show(left+1,top+2,' ',style);
    cout.show(left+1,top+3,' ',style);
    cout.show(left+1,top+4,' ',style);
}

void printN(int left, int top, unsigned char style){
    cout.show(left,top,' ',style);
    cout.show(left,top+1,' ',style);
    cout.show(left,top+2,' ',style);
    cout.show(left,top+3,' ',style);
    cout.show(left,top+4,' ',style);
    cout.show(left+1,top+1,' ',style);
    cout.show(left+2,top+2,' ',style);
    cout.show(left+1,top+2,' ',style);
    cout.show(left+2,top+3,' ',style);
    cout.show(left+3,top,' ',style);
    cout.show(left+3,top+1,' ',style);
    cout.show(left+3,top+2,' ',style);
    cout.show(left+3,top+3,' ',style);
    cout.show(left+3,top+4,' ',style);
}

void printP(int left, int top, unsigned char style){
    cout.show(left,top,' ',style);
    cout.show(left+1,top,' ',style);
    cout.show(left+2,top,' ',style);
    cout.show(left+3,top,' ',style);
    cout.show(left,top+1,' ',style);
    cout.show(left+3,top+1,' ',style);
    cout.show(left,top+2,' ',style);
    cout.show(left+1,top+2,' ',style);
    cout.show(left+2,top+2,' ',style);
    cout.show(left+3,top+2,' ',style);
    cout.show(left,top+3,' ',style);
    cout.show(left,top+4,' ',style);
}

void print1(int left, int top, unsigned char style){
    cout.show(left+2,top,' ',style);
    cout.show(left+1,top+1,' ',style);
    cout.show(left+2,top+1,' ',style);
    cout.show(left+1,top+1,' ',style);
    cout.show(left,top+2,' ',style);
    cout.show(left+1,top+2,' ',style);
    cout.show(left+2,top+2,' ',style);
    cout.show(left+1,top+3,' ',style);
    cout.show(left+2,top+3,' ',style);
    cout.show(left+1,top+4,' ',style);
    cout.show(left+2,top+4,' ',style);
}

void print2(int left, int top, unsigned char style){
    cout.show(left+1,top,' ',style);
    cout.show(left+2,top,' ',style);
    cout.show(left,top+1,' ',style);
    cout.show(left+3,top+1,' ',style);
    cout.show(left+2,top+2,' ',style);
    cout.show(left+3,top+2,' ',style);
    cout.show(left+1,top+3,' ',style);
    cout.show(left,top+4,' ',style);
    cout.show(left+1,top+4,' ',style);
    cout.show(left+2,top+4,' ',style);
    cout.show(left+3,top+4,' ',style);
}

void printP1(int left, int top, unsigned char style){
    printP(left,top,style);
    left+=5;
    print1(left,top,style);
}

void printP2(int left, int top, unsigned char style){
    printP(left,top,style);
    left+=5;
    print2(left,top,style);
}

void printP1Loses(){
    unsigned char style = 4 << 4 | 15;
    int left = p1_left_margin;
    int top = p1_top_margin;
    printP1(left,top,style);
    left+=14;
    //L
    printL(left,top,style);
    left+=5;
    //O
    printO(left,top,style);
    left+=5;
    //S
    printS(left,top,style);
    left+=5;
    //E
    printE(left,top,style);
    left+=5;
    //S
    printS(left,top,style);
}

void printP2Loses(){
    unsigned char style = 4 << 4 | 15;
    int left = p2_left_margin;
    int top = p2_top_margin;
    printP2(left,top,style);
    left+=14;
    //L
    printL(left,top,style);
    left+=5;
    //O
    printO(left,top,style);
    left+=5;
    //S
    printS(left,top,style);
    left+=5;
    //E
    printE(left,top,style);
    left+=5;
    //S
    printS(left,top,style);
}

void printP1Wins(){
    unsigned char style = 2 << 4 | 15;
    int left = p1_left_margin;
    int top = p1_top_margin;
    printP1(left,top,style);
    left+=14;
    printW(left,top,style);
    left+=6;
    printI(left,top,style);
    left+=3;
    printN(left,top,style);
    left+=5;
    printS(left,top,style);
}

void printP2Wins(){
    unsigned char style = 2 << 4 | 15;
    int left = p2_left_margin;
    int top = p2_top_margin;
    printP2(left,top,style);
    left+=14;
    printW(left,top,style);
    left+=6;
    printI(left,top,style);
    left+=3;
    printN(left,top,style);
    left+=5;
    printS(left,top,style);
}

#endif //OOSTUBS_PRINTER_H
