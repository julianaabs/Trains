#ifndef TREM_H
#define TREM_H

#include <QObject>
#include <thread>
#include <chrono>
#include <vector>

#include "semaforo.h"
using namespace std;

class Trem : public QObject
{
    Q_OBJECT
public:
    Trem(int,int,int,std::vector<Semaforo*> *);
    ~Trem();

    int getX();
    void setX(int);
    int getY();
    void setY(int);
    void start();
    void run();
    void setVelocidade(int);
    void setEnable(bool);
    void verifyTrain();

signals:
    void updateGUI(int,int,int);

private:
   std::vector<Semaforo*> *semaphore;
   std::thread threadTrem;
   int id;
   int x;
   int y;
   int velocidade;
   bool enable;
};

#endif // TREM_H



