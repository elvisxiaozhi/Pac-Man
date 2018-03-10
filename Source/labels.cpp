#include "labels.h"
#include <QDebug>
#include <windows.h>

Labels::Labels()
{
    setLabels();
    markBarriers();
    setBarriers();
    setYellowBall();
}

void Labels::setLabels()
{
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            mLabels[i][j] = new QLabel;
            mLabels[i][j]->setText(QString::number(i) + QString::number(j)); //用于调试的时候用
            mLabels[i][j]->setAlignment(Qt::AlignCenter);
            mLabels[i][j]->setFixedSize(25, 25);
        }
    }
}

void Labels::setYellowBall()
{
    QPixmap yellowBallPixmap("://yellow_ball.png");
    int w, h;
    w = mLabels[0][0]->width();
    h = mLabels[0][0]->height();
    mLabels[11][4]->setPixmap(yellowBallPixmap.scaled(w, h, Qt::KeepAspectRatio));
    mLabels[11][4]->setObjectName("Yellow_Ball");
}

void Labels::moveYellowBall(int arrowKey)
{
    int row = 0, col = 0;
    switch (arrowKey) {
    case 1:
        //go up
        qDebug() << "Go up";
        row = -1;
        break;
    case 2:
        //go down
        qDebug() << "Go down";
        row = 1;
        break;
    case 3:
        //go left
        qDebug() << "Go left";
        col = -1;
        break;
    case 4:
        //go right
        qDebug() << "Go right";
        col = 1;
        break;
    default:
        break;
    }

//    int i = 0;
//    while(i < 3) {
        getCurrentYellowBallPos();
        moveCurrentYellowBall(row, col);
//        Sleep(500);
//        i++;
//    }
}

void Labels::markBarriers()
{
    for(int i = 0; i < 2; i++) {
        mLabels[5][12 + i]->setObjectName("Yellow_Letter");
        mLabels[2][22 + i]->setObjectName("Green_Letter");
        mLabels[8][22 + i]->setObjectName("Green_Letter");
        mLabels[10 + i][10]->setObjectName("Barrier_1");
        mLabels[10 + i][24]->setObjectName("Barrier_1");
        mLabels[10][2 + i]->setObjectName("Barrier_1");
    }
    for(int i = 0; i < 3; i++) {
        mLabels[2][17 + i]->setObjectName("Blue_Letter");
        mLabels[5][17 + i]->setObjectName("Blue_Letter");
        mLabels[8][17 + i]->setObjectName("Blue_Letter");
    }
    for(int i = 0; i < 4; i++) {
        mLabels[10][5 + i]->setObjectName("Barrier_1");
    }
    for(int i = 0; i < 5; i++) {
        mLabels[2][5 + i]->setObjectName("Red_Letter");
        mLabels[8][1 + i]->setObjectName("Barrier_1");
        mLabels[10][12 + i]->setObjectName("Barrier_1");
        mLabels[10][18 + i]->setObjectName("Barrier_1");
    }
    for(int i = 0; i < 7; i++) {
        mLabels[2 + i][7]->setObjectName("Red_Letter");
        mLabels[2 + i][11]->setObjectName("Yellow_Letter");
        mLabels[2 + i][14]->setObjectName("Yellow_Letter");
        mLabels[2 + i][16]->setObjectName("Blue_Letter");
        mLabels[2 + i][21]->setObjectName("Green_Letter");
        mLabels[2 + i][24]->setObjectName("Green_Letter");
    }
}

void Labels::setBarriers()
{
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            if(i == 0 || i == 12 || j == 0 || j == 29) {
                mLabels[i][j]->setObjectName("Border");
                mLabels[i][j]->setText("");
                mLabels[i][j]->setStyleSheet("QLabel {background-color: grey}");
            }
            if(mLabels[i][j]->objectName() == "Barrier_1") {
                mLabels[i][j]->setText("");
                mLabels[i][j]->setStyleSheet("QLabel {background-color: purple}");
            }
            if(mLabels[i][j]->objectName() == "Red_Letter") {
                mLabels[i][j]->setText("");
                mLabels[i][j]->setStyleSheet("QLabel {background-color: red}");
            }
            if(mLabels[i][j]->objectName() == "Blue_Letter") {
                mLabels[i][j]->setText("");
                mLabels[i][j]->setStyleSheet("QLabel {background-color: blue}");
            }
            if(mLabels[i][j]->objectName() == "Yellow_Letter") {
                mLabels[i][j]->setText("");
                mLabels[i][j]->setStyleSheet("QLabel {background-color: yellow}");
            }
            if(mLabels[i][j]->objectName() == "Green_Letter") {
                mLabels[i][j]->setText("");
                mLabels[i][j]->setStyleSheet("QLabel {background-color: green}");
            }
        }
    }
}

void Labels::getCurrentYellowBallPos()
{
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            if(mLabels[i][j]->objectName() == "Yellow_Ball") {
                currentRow = i;
                currentCol = j;
                break;
            }
        }
    }
    qDebug() << currentRow << currentCol;
}

void Labels::moveCurrentYellowBall(int row, int col)
{
    QPixmap yellowBallPixmap("://yellow_ball.png");
    QPixmap emptyPixmap;

    int w, h;
    w = mLabels[0][0]->width();
    h = mLabels[0][0]->height();

    if(mLabels[currentRow + row][currentCol + col]->objectName() != "Barrier") {
        mLabels[currentRow][currentCol]->setPixmap(emptyPixmap);
        mLabels[currentRow][currentCol]->setObjectName("");

        mLabels[currentRow + row][currentCol + col]->setPixmap(yellowBallPixmap.scaled(w, h, Qt::KeepAspectRatio));
        mLabels[currentRow + row][currentCol + col]->setObjectName("Yellow_Ball");
    }

    getCurrentYellowBallPos();
}
