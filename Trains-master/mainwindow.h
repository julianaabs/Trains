#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "trem.h"
#include <QMainWindow>

#include <vector>

#include "semaforo.h"

using namespace std;

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void stopAlltrains();
    void startSingleTrain(int);
    void stopSingleTrain(int);
    void server();
    //static void socketHandler(MainWindow *window, int socketDescriptor, Data data);

public slots:
    void updateInterface(int,int,int);

private:
    Ui::MainWindow *ui;
    std::vector<Trem*> trens;
    std::vector<Semaforo*> *semaphore;
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
};

#endif // MAINWINDOW_H
