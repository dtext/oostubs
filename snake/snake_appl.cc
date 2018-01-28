#include <snake/snake_appl.h>
#include <syscall/guarded_keyboard.h>
#include <device/cgastr.h>
#include <syscall/guarded_organizer.h>
#include <syscall/guarded_buzzer.h>

SnakeData snakeData;

void SnakeApplication::action() {
    Guarded_Buzzer buzzer;
    buzzer.set(1000);

    cout.clear();
    printMessage("Druecke Leertaste um zu starten!");

    Key pressed;
    while (pressed.ascii() != ' ') {
        pressed = keyboard.getkey();
    }

    cout.clear();
    cout.setpos(0,0);
    printBorder();
    cout.show(snakeData.p1.getX(),snakeData.p1.getY(),' ',3 << 4 | 15);
    cout.show(snakeData.p2.getX(),snakeData.p2.getY(),' ',4 << 4 | 15);

    while (true) {
        buzzer.sleep();
        snakeData.p1.move();
        snakeData.p2.move();
        cout.show(snakeData.p1.getX(),snakeData.p1.getY(),' ',3 << 4 | 15);
        cout.show(snakeData.p2.getX(),snakeData.p2.getY(),' ',4 << 4 | 15);
        if((collides(snakeData.p1) || isOutOfField(snakeData.p1))
            && (collides(snakeData.p2) || isOutOfField(snakeData.p2))){
            //unentschieden
            printMessage("Unentschieden!");
        }else if(collides(snakeData.p1) || isOutOfField(snakeData.p1)){
            //Spieler 1 hat verloren
            printMessage("Spieler 1 hat verloren!");
        }else if(collides(snakeData.p2) || isOutOfField(snakeData.p2)){
            //Spieler 2 hat verloren
            printMessage("Spieler 2 hat verloren!");
        }else{
            //weiter
            snakeData.field[snakeData.p1.getY()][snakeData.p1.getX()] = 1;
            snakeData.field[snakeData.p2.getY()][snakeData.p2.getX()] = 2;
        }

    }
}

void SnakeApplication::printBorder(){
    for(int row=0;row<CGA_Screen::ROW_COUNT;row++){
        cout.show(0,row, ' ',2 << 4 | 15);
        cout.show(CGA_Screen::ROW_SIZE-1,row, ' ',2 << 4 | 15);
    }
    for(int column=0;column<CGA_Screen::ROW_SIZE;column++){
        cout.show(column,0, ' ',2 << 4 | 15);
        cout.show(column,CGA_Screen::ROW_COUNT-1, ' ',2 << 4 | 15);
    }
}

void SnakeApplication::printMessage(char* message) {
    int margin_left = 7;
    int margin_right = (80 - margin_left);
    int margin_top = 50;
    int x, y;
    for (int i = 0; message[i]; i++) {
        cout.getpos(x, y);
        cout.show(x, y, message[i], 1 << 4 | 15);
        cout.setpos(++x, y);
    }
}

bool SnakeApplication::isOutOfField(Player player) {
    return player.getY() <=0 || player.getY() >= CGA_Screen::ROW_COUNT-2
            || player.getX() <=0 || player.getX() >= CGA_Screen::ROW_SIZE-2;
}

bool SnakeApplication::collides(Player player) {
    return snakeData.field[player.getY()][player.getX()] != 0;
}