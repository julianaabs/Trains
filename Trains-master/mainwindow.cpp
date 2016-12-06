#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    trem1 = new Trem(1,160,30);
    trem2 = new Trem(2,160,130);
    trem3 = new Trem(3, 300, 130);
    trem4 = new Trem(4, 300, 230);

    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::updateInterface(int id, int x, int y) {
//    switch(id){
//        case 1:
//            ui->labelTrain1->setGeometry(x,y,210,20);
//            break;
//        case 2:
//            ui->labelTrain2->setGeometry(x,y,150,170);
//            break;
//        case 3:
//            ui->labelTrain3->setGeometry(x,y,430,170);
//            break;
//        case 4:
//            ui->labelTrain4->setGeometry(x,y,290,310);
//            break;
//        default:
//            break;
//    }
//}

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

void MainWindow::startAllTrains() {

}

void MainWindow::stopAlltrains() {

}

void MainWindow::startSingleTrain(int) {

}

void MainWindow::stopSingleTrain(int) {

}

void MainWindow::server() {

}

