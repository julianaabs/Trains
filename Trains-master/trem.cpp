#include "trem.h"
#include <iostream>


Trem::Trem(int id, int x, int y, std::vector<Semaforo*> *semaphore)
{
    this->id = id;
    this->x = x;
    this->y = y;
    velocidade = 250;
    enable = true;
    this->semaphore = semaphore;
}

Trem::~Trem()
{
    threadTrem.join();
}

int Trem::getX() {
    return this->x;
}

void Trem::setX(int px) {
    this->x = px;
}

int Trem::getY() {
    return this->y;
}

void Trem::setY(int py) {
    this->y = py;
}

void Trem::setVelocidade(int velocidade)
{
    this->velocidade = velocidade;
}

void Trem::setEnable(bool enable)
{
    this->enable = enable;
}

void Trem::start()
{
    threadTrem = std::thread(&Trem::run,this);
}

void Trem::run()
{
    while(true){
        switch(id){
        case 1:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 20 && x > 150)
                    x-=10;
                else if (x == 150 && y < 120)
                    y+=10;
                else if (x < 290 && y == 120)
                    x+=10;
                else if (x == 290 && y > 20)
                    y-=10;
                else
                    x-=10;
            }
            break;
        case 2:
            if(enable)
            {
                emit updateGUI(id,x,y);
                if (x == 150 && y > 120)
                    y-=10;
                else if (y == 220 && x > 150)
                    x-=10;
                else if (x == 290 && y < 220)
                    y+=10;
                else if (y == 120 && x < 290)
                    x+=10;
                else
                    y-=10;
            }
            break;
        case 3:
            if(enable)
            {
                emit updateGUI(id,x,y);
                if (y == 120 && x < 430)
                    x+=10;
                else if (x == 430 && y < 220)
                    y+=10;
                else if (y == 220 && x > 290)
                    x-=10;
                else if (x == 290 && y > 120)
                    y-=10;
                else
                    y-=10;
            }
            break;
        case 4:
            if(enable)
            {
                emit updateGUI(id,x,y);
                if (y == 220 && x < 430)
                    x+=10;
                else if (x == 430 && y < 320)
                    y+=10;
                else if (y == 320 && x > 290)
                    x-=10;
                else if (x == 290 && y < 220)
                    y-=10;
                else
                    y-=10;
            }
            break;
        default:
            break;
        }
        verifyTrain(); // test if the rails is being used.
        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}

void Trem::verifyTrain() {
    if(id == 1) {
        if(x == 150 && y == 100) {
            semaphore->at(0)->P(); // bloc the critic area  or stop before the critic area.
        }
        if(x == 290 && y == 100) {
            semaphore->at(0)->V(); // block the critic area
        }
    }
    else if(id == 2) { // blue train
        if(x == 150 && y == 140) {
            semaphore->at(0)->P(); // bloc the critic area  or stop before the critic area.
            semaphore->at(1)->P(); // bloc the critic area  or stop before the critic area.
        }
        if(x == 270 && y == 220) {
            semaphore->at(0)->V(); // unblock the critic area.
            semaphore->at(1)->V(); // unblock the critic area.
        }
    }
    else if(id == 3) {
        if(x == 430 && y == 200) {
            semaphore->at(1)->P(); // bloc the critic area  or stop before the critic area.
            semaphore->at(2)->P(); // bloc the critic area  or stop before the critic area.
        }
        if(x == 310 && y == 120) {
            semaphore->at(1)->V(); // unblock the critic area.
            semaphore->at(2)->V(); // unblock the critic area.
        }
    }
    else {
        if(x == 290 && y == 240) {
            semaphore->at(2)->P(); // block the critic area
        }
        if(x == 430 && y == 240) {
            semaphore->at(2)->V(); // block the critic area
        }
    }
}

