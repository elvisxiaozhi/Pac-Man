#include "mainlayout.h"
#include <QDebug>
#include <QKeyEvent>
#include <QThread>

MainLayout::MainLayout(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Pac-Man(Made by Theodore)");
    mainInterface = new QWidget(this);
    setCentralWidget(mainInterface);
    gLayout = new QGridLayout(mainInterface);
    mainInterface->setLayout(gLayout);
    gLayout->setSpacing(0);

    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            gLayout->addWidget(setLabels.mLabels[i][j], i, j);
        }
    }

    setDots.generateFiveSpecialDots();

    setLabels.updateLabels();
    setLabels.setBarriers();
    setLabels.setYellowBall();
    setLabels.setDots();
}

MainLayout::~MainLayout()
{

}

void MainLayout::keyPressEvent(QKeyEvent *event)
{
    int arrowKey = 0;
    if(event->key() == Qt::Key_Up) {
        arrowKey = 1;
        setLabels.moveYellowBall(arrowKey);
    }
    if(event->key() == Qt::Key_Down) {
        arrowKey = 2;
        setLabels.moveYellowBall(arrowKey);
    }
    if(event->key() == Qt::Key_Left) {
        arrowKey = 3;
        setLabels.moveYellowBall(arrowKey);
    }
    if(event->key() == Qt::Key_Right) {
        arrowKey = 4;
        setLabels.moveYellowBall(arrowKey);
    }
}
