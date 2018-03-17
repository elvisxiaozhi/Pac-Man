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

    setDots.generateFiveSpecialDots();

    setLabels.updateLabels();
    setLabels.setDots();
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

void MainLayout::afterTimeout()
{
    setLabels.moveYellowBall(arrowKey);
}
