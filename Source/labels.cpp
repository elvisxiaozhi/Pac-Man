#include "labels.h"
#include <QDebug>
#include <windows.h>

QLabel **pixelLabels = new QLabel*[13];

Labels::Labels()
{
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            //pixelLabels[i][j].setText(QString::number(i) + QString::number(j)); //用于调试的时候用

            mLabels[i][j] = new QLabel;
            mLabels[i][j]->setAlignment(Qt::AlignCenter);
            mLabels[i][j]->setFixedSize(25, 25);
        }
    }
    setEmptyPlaces();
}

void Labels::updateLabels()
{
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            mLabels[i][j]->setObjectName(pixelLabels[i][j].objectName());
        }
    }
}

void Labels::updateExternLabels()
{
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            pixelLabels[i][j].setObjectName(mLabels[i][j]->objectName());
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

    updateExternLabels();
}

void Labels::moveYellowBall(int arrowKey)
{
    int row = 0, col = 0;
    switch (arrowKey) {
    case 1:
        //go up
        row = -1;
        break;
    case 2:
        //go down
        row = 1;
        break;
    case 3:
        //go left
        col = -1;
        break;
    case 4:
        //go right
        col = 1;
        break;
    default:
        break;
    }

    getCurrentYellowBallPos();
    moveCurrentYellowBall(row, col);

    updateExternLabels();
}

void Labels::testing()
{
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            mLabels[i][j]->setText(QString::number(i) + QString::number(j));
        }
    }
}

void Labels::setEmptyPlaces()
{
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 2; j++) {
            mLabels[3 + i][22 + j]->setObjectName("Empty");
        }
    }

    updateExternLabels();
}

void Labels::setBarriers()
{
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            if(i == 0 || i == 12 || j == 0 || j == 29) {
                mLabels[i][j]->setObjectName("Border_Barrier");
                mLabels[i][j]->setStyleSheet("QLabel {background-color: grey}");
            }
            if(mLabels[i][j]->objectName() == "Road_Barrier") {
                mLabels[i][j]->setStyleSheet("QLabel {background-color: purple}");
            }
            if(mLabels[i][j]->objectName() == "Red_Letter") {
                mLabels[i][j]->setStyleSheet("QLabel {background-color: red}");
            }
            if(mLabels[i][j]->objectName() == "Blue_Letter") {
                mLabels[i][j]->setStyleSheet("QLabel {background-color: blue}");
            }
            if(mLabels[i][j]->objectName() == "Yellow_Letter") {
                mLabels[i][j]->setStyleSheet("QLabel {background-color: yellow}");
            }
            if(mLabels[i][j]->objectName() == "Green_Letter") {
                mLabels[i][j]->setStyleSheet("QLabel {background-color: green}");
            }
        }
    }

    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            if(mLabels[i][j]->objectName() == "Border_Barrier" || mLabels[i][j]->objectName() == "Road_Barrier" ||
                    mLabels[i][j]->objectName() == "Red_Letter" || mLabels[i][j]->objectName() == "Blue_Letter" ||
                    mLabels[i][j]->objectName() == "Yellow_Letter" || mLabels[i][j]->objectName() == "Green_Letter") {
                mLabels[i][j]->setObjectName("Barrier");
            }
        }
    }

    updateExternLabels();
}

void Labels::setDots()
{
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            if(mLabels[i][j]->objectName() == "") {
                mLabels[i][j]->setObjectName("Dot");
                mLabels[i][j]->setText("•");
                mLabels[i][j]->setStyleSheet("QLabel {color : orange; font-size: 25px}");
            }

            if(mLabels[i][j]->objectName() == "Special_Dot") {
                mLabels[i][j]->setText("•");
                mLabels[i][j]->setStyleSheet("QLabel {color : blue; font-size: 40px}");
            }
        }
    }

    updateExternLabels();
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
