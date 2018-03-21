#include "mainlayout.h"
#include <QDebug>
#include <QKeyEvent>

MainLayout::MainLayout(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Pac-Man");
    mainInterface = new QWidget(this);
    setCentralWidget(mainInterface);
    gLayout = new QGridLayout(mainInterface);
    mainInterface->setLayout(gLayout);
    gLayout->setSpacing(0);

    setTimer = new QTimer(this); //timer is used for keeping objects moving, also need to set the parent to this, or the program will end forcely after closing
    connect(setTimer, &QTimer::timeout, this, &MainLayout::afterTimeout);
    ghostsTimer = new QTimer(this);
    connect(ghostsTimer, &QTimer::timeout, &setLabels, &Labels::moveGhosts);
    countdownTimer = new QTimer(this);
    connect(countdownTimer, &QTimer::timeout, this, &MainLayout::afterCountingDown);

    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            gLayout->addWidget(setLabels.mLabels[i][j], i, j);
        }
    }

    iterateTimes = 0;

    setLabels.updateLabels(); //update first, or the barriers will not show
    setLabels.setBarriers();
    setLabels.setPacMan();

    setDots.generateFiveSpecialDots();

    setLabels.updateLabels();

    setLabels.setDots();
    dotNumber = setDots.countDotNumber();

    setLabels.setGhosts();

    connect(&setMsBox, &MessageBoxes::playAgain, this, &MainLayout::playAgain);
    connect(&setLabels, &Labels::gameOver, this, &MainLayout::gameOver);
    connect(&setLabels, &Labels::ateSpecialDot, this, &MainLayout::specialDotEffect);
    connect(this, &MainLayout::terrifiedGhosts, &setLabels, &Labels::setTerrifiedGhosts);
    connect(this, &MainLayout::effectGone, &setLabels, &Labels::setGhosts);
}

MainLayout::~MainLayout()
{

}

void MainLayout::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up) {
        arrowKey = 1;
    }
    if(event->key() == Qt::Key_Down) {
        arrowKey = 2;
    }
    if(event->key() == Qt::Key_Left) {
        arrowKey = 3;
    }
    if(event->key() == Qt::Key_Right) {
        arrowKey = 4;
    }
    setTimer->start(200);
    iterateTimes++;
    if(iterateTimes == 1) {
        ghostsTimer->start(150);
    }
}

bool MainLayout::checkWin()
{
    int ateNumber = 0;
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
        ghostsTimer->stop();
        setMsBox.playAgainMsBox.setWindowTitle("You Won");
        setMsBox.showPlayAgainMsBox();
    }
}

void MainLayout::playAgain()
{
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            if(pixelLabels[i][j].objectName() == "Special_Dot" || pixelLabels[i][j].objectName() == "Dot") {
                pixelLabels[i][j].setObjectName("");
            }
            if(pixelLabels[i][j].objectName() == "Pac_Man") {
                pixelLabels[i][j].setObjectName("");
            }
        }
    }

    iterateTimes = 0;

    setLabels.updateLabels(); //update first, or there will be more than five special dots
    setLabels.setPacMan();
    setDots.generateFiveSpecialDots();
    setLabels.updateLabels();
    setLabels.setDots();
    setLabels.setGhosts(); //setGhosts must be behide setDots, or ghosts won't show
}

void MainLayout::gameOver()
{
    setTimer->stop();
    ghostsTimer->stop();
    setMsBox.playAgainMsBox.setWindowTitle("You Lost");
    setMsBox.showPlayAgainMsBox();
}

void MainLayout::specialDotEffect()
{
    ghostsTimer->stop();
    countdownTime = 0;
    countdownTimer->start(1000);
    emit terrifiedGhosts();
}

void MainLayout::afterCountingDown()
{
    countdownTime++;
    if(countdownTime == 3) {
        countdownTimer->stop();
        ghostsTimer->start(150);
        emit effectGone();
    }
}
