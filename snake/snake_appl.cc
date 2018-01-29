#include <snake/snake_appl.h>
#include <syscall/guarded_keyboard.h>
#include <device/cgastr.h>
#include <syscall/guarded_organizer.h>
#include <syscall/guarded_buzzer.h>
#include <snake/printer.h>

SnakeData snakeData;
Guarded_Semaphore gameDataSemaphore(1);

void SnakeApplication::action() {
    cout.clear();
    printMessage("Druecke Leertaste um zu starten!");
    {
        Key pressed;
        while (pressed.ascii() != ' ') {
            pressed = keyboard.getkey();
        }
    }

    while (true) {
        gameLoop();
        printMessage("Druecke Leertaste um neu zu starten!");
        {
            Key pressed;
            while (pressed.ascii() != ' ') {
                pressed = keyboard.getkey();
            }
        }
    }
}

void SnakeApplication::gameLoop() {
    Guarded_Buzzer buzzer;
    buzzer.set(1000);
    cout.clear();
    cout.setpos(10,1);
    printBorder();
    gameDataSemaphore.wait();
    snakeData.reset();
    gameDataSemaphore.signal();
    cout.show(snakeData.p1.getX(),snakeData.p1.getY(),' ',snakeData.p1.getStyle());
    cout.show(snakeData.p2.getX(),snakeData.p2.getY(),' ',snakeData.p2.getStyle());
    while (true) {
        buzzer.sleep();
        gameDataSemaphore.wait();
        snakeData.p1.move();
        snakeData.p2.move();
        gameDataSemaphore.signal();
        cout.show(snakeData.p1.getX(),snakeData.p1.getY(),' ',snakeData.p1.getStyle());
        cout.show(snakeData.p2.getX(),snakeData.p2.getY(),' ',snakeData.p2.getStyle());
        if((collides(snakeData.p1) || isOutOfField(snakeData.p1))
           && (collides(snakeData.p2) || isOutOfField(snakeData.p2))){
            //unentschieden
            printP1Loses();
            printP2Loses();
            break;
        }else if(collides(snakeData.p1) || isOutOfField(snakeData.p1)){
            //Spieler 1 hat verloren
            printP1Loses();
            printP2Wins();
            break;
        }else if(collides(snakeData.p2) || isOutOfField(snakeData.p2)){
            //Spieler 2 hat verloren
            printP1Wins();
            printP2Loses();
            break;
        }else{
            //weiter
            gameDataSemaphore.wait();
            snakeData.field[snakeData.p1.getY()][snakeData.p1.getX()] = 1;
            snakeData.field[snakeData.p2.getY()][snakeData.p2.getX()] = 2;
            gameDataSemaphore.signal();
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
    int x, y;
    for (int i = 0; message[i]; i++) {
        cout.getpos(x, y);
        cout.show(x, y, message[i],15);
        cout.setpos(++x, y);
    }
}

bool SnakeApplication::isOutOfField(Player player) {
    return player.getY() <=0 || player.getY() >= CGA_Screen::ROW_COUNT-1
            || player.getX() <=0 || player.getX() >= CGA_Screen::ROW_SIZE-1;
}

bool SnakeApplication::collides(Player player) {
    return snakeData.field[player.getY()][player.getX()] != 0;
}

