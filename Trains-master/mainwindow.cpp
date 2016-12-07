#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // start semaphores
    semaphore = new std::vector<Semaforo*>();
    for (int i = 1; i <= 3; i++) {
        semaphore->push_back(new Semaforo(i, 1, IPC_CREAT|0600));  // Critical Section %i
    }

    trem1 = new Trem(1, 180, 20, semaphore);
    trem2 = new Trem(2, 150, 170, semaphore);
    trem3 = new Trem(3, 430, 160, semaphore);
    trem4 = new Trem(4, 370, 320, semaphore);

    trens.push_back(trem1);
    trens.push_back(trem2);
    trens.push_back(trem3);
    trens.push_back(trem4);

    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();

    server();
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::updateInterface
 * @param id
 * @param x
 * @param y
 */
void MainWindow::updateInterface(int id, int x, int y) {
    switch(id){
        case 1:
            ui->labelTrain1->setGeometry(x,y,20,20);
            break;
        case 2:
            ui->labelTrain2->setGeometry(x,y,20,20);
            break;
        case 3:
            ui->labelTrain3->setGeometry(x,y,20,20);
            break;
        case 4:
            ui->labelTrain4->setGeometry(x,y,20,20);
            break;
        default:
            break;
    }
}

/**
 * @brief MainWindow::stopAlltrains is a function that stop al the trains.
 */
void MainWindow::stopAlltrains() {
    trem1->setEnable(false);
    trem2->setEnable(false);
    trem3->setEnable(false);
    trem4->setEnable(false);
}

/**
 * @brief MainWindow::startSingleTrain is a function that make a train "walk"
 * @param index     Is the parameter that receive the index of the train to stop
 */
void MainWindow::startSingleTrain(int index) {
    trens[index]->setEnable(true);
}

void MainWindow::stopSingleTrain(int index) {
    trens[index]->setEnable(false);
}

/**
 * @brief MainWindow::server is a function that start the server TCP.
 */
void MainWindow::server() {

}


