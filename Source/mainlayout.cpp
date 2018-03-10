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
            gLayout->addWidget(pixelLabels.mLabels[i][j], i, j);
        }
    }
}

MainLayout::~MainLayout()
{

}

void MainLayout::keyPressEvent(QKeyEvent *event)
{
    int arrowKey = 0;
    if(event->key() == Qt::Key_Left) {
        arrowKey = 3;
//        while(true) {
            pixelLabels.moveYellowBall(arrowKey);
//            QThread::sleep(500);
//        }
    }
}
