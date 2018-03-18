#include "mainlayout.h"
#include <QDebug>
#include <QKeyEvent>
#include "windows.h"

MainLayout::MainLayout(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Pac-Man(Made by Theodore)");
    mainInterface = new QWidget(this);
    setCentralWidget(mainInterface);
    gLayout = new QGridLayout(mainInterface);
    mainInterface->setLayout(gLayout);
    gLayout->setSpacing(0);

    setTimer = new QTimer(); //timer is used for keeping objects moving
    connect(setTimer, &QTimer::timeout, this, &MainLayout::afterTimeout);

    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            gLayout->addWidget(setLabels.mLabels[i][j], i, j);
        }
    }

    setLabels.updateLabels();
    setLabels.setBarriers();
    setLabels.setYellowBall();
    setLabels.setGhosts();

    setDots.generateFiveSpecialDots();

    setLabels.updateLabels();
    setLabels.setDots();

    dotNumber = setDots.countDotNumber();

    connect(&setLabels, &Labels::gameOver, this, &MainLayout::gameOver);
}

MainLayout::~MainLayout()
{

}

void MainLayout::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up) {
        arrowKey = 1;
        setTimer->start(200);
    }
    if(event->key() == Qt::Key_Down) {
        arrowKey = 2;
        setTimer->start(200);
    }
    if(event->key() == Qt::Key_Left) {
        arrowKey = 3;
        setTimer->start(200);
    }
    if(event->key() == Qt::Key_Right) {
        arrowKey = 4;
        setTimer->start(200);
    }
}

bool MainLayout::checkWin()
{
    int ateNumber;
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            if(pixelLabels[i][j].objectName() == "") {
                ateNumber++;
            }
        }
    }
    if(ateNumber == dotNumber) {
        return true;
    }
    return false;
}

void MainLayout::afterTimeout()
{
    setLabels.moveYellowBall(arrowKey);
    if(checkWin() == true) {
        setTimer->stop();
        setMsBox.playAgainMsBox.setWindowTitle("You Won");
        setMsBox.showPlayAgainMsBox();
    }
}

void MainLayout::gameOver()
{
    setTimer->stop();
    setMsBox.playAgainMsBox.setWindowTitle("You Lost");
    setMsBox.showPlayAgainMsBox();
}
