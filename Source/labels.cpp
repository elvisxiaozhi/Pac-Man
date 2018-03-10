#include "labels.h"
#include <QDebug>
#include <QThread>

Labels::Labels()
{
    setLabels();
    setLetters();
    setBorders();
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

void Labels::setLetters()
{
    for(int i = 0; i < 5; i++) {
        mLabels[2][5 + i]->setStyleSheet("QLabel {background-color: red/*; border: 1px solid blue;*/}");
        mLabels[2][5 + i]->setText("");
    }
    for(int i = 0; i < 7; i++) {
        mLabels[2 + i][7]->setStyleSheet("QLabel {background-color: red}");
        mLabels[2 + i][7]->setText("");
        mLabels[2 + i][11]->setStyleSheet("QLabel {background-color: yellow}");
        mLabels[2 + i][11]->setText("");
        mLabels[2 + i][14]->setStyleSheet("QLabel {background-color: yellow}");
        mLabels[2 + i][14]->setText("");
        mLabels[2 + i][16]->setStyleSheet("QLabel {background-color: blue}");
        mLabels[2 + i][16]->setText("");
        mLabels[2 + i][21]->setStyleSheet("QLabel {background-color: green}");
        mLabels[2 + i][21]->setText("");
        mLabels[2 + i][24]->setStyleSheet("QLabel {background-color: green}");
        mLabels[2 + i][24]->setText("");
    }
    for(int i = 0; i < 2; i++) {
        mLabels[5][12 + i]->setStyleSheet("QLabel {background-color: yellow}");
        mLabels[5][12 + i]->setText("");
        mLabels[2][22 + i]->setStyleSheet("QLabel {background-color: green}");
        mLabels[2][22 + i]->setText("");
        mLabels[8][22 + i]->setStyleSheet("QLabel {background-color: green}");
        mLabels[8][22 + i]->setText("");
    }
    for(int i = 0; i < 3; i++) {
        mLabels[2][17 + i]->setStyleSheet("QLabel {background-color: blue}");
        mLabels[2][17 + i]->setText("");
        mLabels[5][17 + i]->setStyleSheet("QLabel {background-color: blue}");
        mLabels[5][17 + i]->setText("");
        mLabels[8][17 + i]->setStyleSheet("QLabel {background-color: blue}");
        mLabels[8][17 + i]->setText("");
    }
}

void Labels::setBorders()
{
    for(int i = 0; i < 30; i++) {
        mLabels[0][0 + i]->setStyleSheet("QLabel {background-color: black; border-top: 2px solid blue; border-bottom: 2px solid blue;}");
        mLabels[0][0 + i]->setText("");
        mLabels[0][0 + i]->setObjectName("Barrier");

        //“12（第一位数）”应随着row的数量而变化
        mLabels[12][0 + i]->setStyleSheet("QLabel {background-color: black; border-top: 2px solid blue; border-bottom: 2px solid blue;}");
        mLabels[12][0 + i]->setText("");
        mLabels[12][0 + i]->setObjectName("Barrier");
    }
    for(int i = 0; i < 13; i++) {
        mLabels[0 + i][0]->setStyleSheet("QLabel {background-color: black; border-left: 2px solid blue; border-right: 2px solid blue;}");
        mLabels[0 + i][0]->setText("");
        mLabels[0 + i][0]->setObjectName("Barrier");

        mLabels[0 + i][29]->setStyleSheet("QLabel {background-color: black; border-left: 2px solid blue; border-right: 2px solid blue;}");
        mLabels[0 + i][29]->setText("");
        mLabels[0 + i][29]->setObjectName("Barrier");
    }
    for(int i = 0; i < 2; i++) {
        mLabels[10 + i][10]->setStyleSheet("QLabel {background-color: black; border-left: 2px solid blue; border-right: 2px solid blue;}");
        mLabels[10 + i][10]->setText("");
        mLabels[10 + i][10]->setObjectName("Barrier");

        mLabels[10 + i][24]->setStyleSheet("QLabel {background-color: black; border-left: 2px solid blue; border-right: 2px solid blue;}");
        mLabels[10 + i][24]->setText("");
        mLabels[10 + i][24]->setObjectName("Barrier");

        mLabels[10][2 + i]->setStyleSheet("QLabel {background-color: black; border-left: 2px solid blue; border-right: 2px solid blue;}");
        mLabels[10][2 + i]->setText("");
        mLabels[10][2 + i]->setObjectName("Barrier");
    }
    for(int i = 0; i < 4; i++) {
        mLabels[10][5 + i]->setStyleSheet("QLabel {background-color: black; border-left: 2px solid blue; border-right: 2px solid blue;}");
        mLabels[10][5 + i]->setText("");
        mLabels[10][5 + i]->setObjectName("Barrier");
    }
    for(int i = 0; i < 5; i++) {
        mLabels[8][1 + i]->setStyleSheet("QLabel {background-color: black; border-top: 2px solid blue; border-bottom: 2px solid blue;}");
        mLabels[8][1 + i]->setText("");
        mLabels[8][1 + i]->setObjectName("Barrier");
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
    switch (arrowKey) {
    case 3:
        //go left
        qDebug() << "Go left";
        getCurrentYellowBallPos();
        moveCurrentYellowBall(arrowKey);
        break;
    default:
        break;
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

void Labels::moveCurrentYellowBall(int moveDirection)
{
    QPixmap yellowBallPixmap("://yellow_ball.png");
    QPixmap emptyPixmap;

    int w, h;
    w = mLabels[0][0]->width();
    h = mLabels[0][0]->height();

    switch (moveDirection) {
    case 3:
        //go left
        if(mLabels[currentRow][currentCol - 1]->objectName() != "Barrier") {
            mLabels[currentRow][currentCol]->setPixmap(emptyPixmap);

            mLabels[currentRow][currentCol - 1]->setPixmap(yellowBallPixmap.scaled(w, h, Qt::KeepAspectRatio));
            mLabels[currentRow][currentCol - 1]->setObjectName("Yellow_Ball");
        }
        break;
    default:
        break;
    }

    getCurrentYellowBallPos();
}
