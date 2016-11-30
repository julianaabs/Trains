#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    trem1 = new Trem(1,160,30);
    trem2 = new Trem(2,160,30);
    trem3 = new Trem(3, 150, 180);
    trem4 = new Trem(4, 290, 300);
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    trem1->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateInterface(int id, int x, int y)
{
    switch(id){
        case 1:
            ui->labelTrem01->setGeometry(x,y,20,20);
            break;
        case 2:
            break;
        default:
            break;
    }
}

