#include "labels.h"
#include <QDebug>
#include <QKeyEvent>
#include <windows.h>

QLabel **pixelLabels = new QLabel*[13];

Labels::Labels()
{
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            mLabels[i][j] = new QLabel;
            mLabels[i][j]->setAlignment(Qt::AlignCenter);
            mLabels[i][j]->setFixedSize(25, 25);
        }
    }
    pixmapWidth = mLabels[0][0]->width();
    pixmapHeight = mLabels[0][0]->height();
    setEmptyPlaces();
    connect(&setGhostsMovement, &Ghosts::ghostsOnTheMove, this, &Labels::resetBeneathGhosts);
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

void Labels::setPacMan()
{
    mLabels[11][17]->setPixmap(QPixmap(":/pac-man.png").scaled(pixmapWidth, pixmapHeight, Qt::KeepAspectRatio));
    mLabels[11][17]->setObjectName("Pac_Man");

    updateExternLabels();
}

void Labels::setGhosts()
{
    mLabels[setGhostsMovement.ghostsInfo["Ghost_1"].first][setGhostsMovement.ghostsInfo["Ghost_1"].second]->setPixmap(QPixmap(":/ghost-1.png").scaled(pixmapWidth, pixmapHeight, Qt::KeepAspectRatio));
    mLabels[setGhostsMovement.ghostsInfo["Ghost_2"].first][setGhostsMovement.ghostsInfo["Ghost_2"].second]->setPixmap(QPixmap(":/ghost-2.png").scaled(pixmapWidth, pixmapHeight, Qt::KeepAspectRatio));
    mLabels[setGhostsMovement.ghostsInfo["Ghost_3"].first][setGhostsMovement.ghostsInfo["Ghost_3"].second]->setPixmap(QPixmap(":/ghost-3.png").scaled(pixmapWidth, pixmapHeight, Qt::KeepAspectRatio));
    mLabels[setGhostsMovement.ghostsInfo["Ghost_4"].first][setGhostsMovement.ghostsInfo["Ghost_4"].second]->setPixmap(QPixmap(":/ghost-4.png").scaled(pixmapWidth, pixmapHeight, Qt::KeepAspectRatio));

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
            if(mLabels[i][j]->objectName() == "Pac_Man") {
                currentRow = i;
                currentCol = j;
                break;
            }
        }
    }
}

void Labels::moveCurrentYellowBall(int row, int col)
{
    if(mLabels[currentRow + row][currentCol + col]->objectName() != "Barrier") {
        if(mLabels[currentRow + row][currentCol + col]->objectName() == "Special_Dot") {
            emit ateSpecialDot();
        }
        mLabels[currentRow][currentCol]->setPixmap(QPixmap());
        mLabels[currentRow][currentCol]->setObjectName("");
        mLabels[currentRow + row][currentCol + col]->setPixmap(QPixmap(":/pac-man.png").scaled(pixmapWidth, pixmapHeight, Qt::KeepAspectRatio));
        mLabels[currentRow + row][currentCol + col]->setObjectName("Pac_Man");
    }

    getCurrentYellowBallPos();
}

void Labels::getBeneathGhostsInfo()
{
}

void Labels::resetBeneathGhosts()
{
    if(mLabels[setGhostsMovement.ghostsInfo["Ghost_1"].first][setGhostsMovement.ghostsInfo["Ghost_1"].second]->objectName() == "Dot" || mLabels[setGhostsMovement.ghostsInfo["Ghost_1"].first][setGhostsMovement.ghostsInfo["Ghost_1"].second]->objectName() == "Special_Dot") {
        mLabels[setGhostsMovement.ghostsInfo["Ghost_1"].first][setGhostsMovement.ghostsInfo["Ghost_1"].second]->setText("•");
    }
    if(mLabels[setGhostsMovement.ghostsInfo["Ghost_1"].first][setGhostsMovement.ghostsInfo["Ghost_1"].second]->objectName() == "") {
        mLabels[setGhostsMovement.ghostsInfo["Ghost_1"].first][setGhostsMovement.ghostsInfo["Ghost_1"].second]->setText("•"); //need to set an unempty text first to avoid showing multiple ghost
        mLabels[setGhostsMovement.ghostsInfo["Ghost_1"].first][setGhostsMovement.ghostsInfo["Ghost_1"].second]->setText("");
    }

    if(mLabels[setGhostsMovement.ghostsInfo["Ghost_2"].first][setGhostsMovement.ghostsInfo["Ghost_2"].second]->objectName() == "Dot" || mLabels[setGhostsMovement.ghostsInfo["Ghost_2"].first][setGhostsMovement.ghostsInfo["Ghost_2"].second]->objectName() == "Special_Dot") {
        mLabels[setGhostsMovement.ghostsInfo["Ghost_2"].first][setGhostsMovement.ghostsInfo["Ghost_2"].second]->setText("•");
    }
    if(mLabels[setGhostsMovement.ghostsInfo["Ghost_2"].first][setGhostsMovement.ghostsInfo["Ghost_2"].second]->objectName() == "") {
        mLabels[setGhostsMovement.ghostsInfo["Ghost_2"].first][setGhostsMovement.ghostsInfo["Ghost_2"].second]->setText("•");
        mLabels[setGhostsMovement.ghostsInfo["Ghost_2"].first][setGhostsMovement.ghostsInfo["Ghost_2"].second]->setText("");
    }

    if(mLabels[setGhostsMovement.ghostsInfo["Ghost_3"].first][setGhostsMovement.ghostsInfo["Ghost_3"].second]->objectName() == "Dot" || mLabels[setGhostsMovement.ghostsInfo["Ghost_3"].first][setGhostsMovement.ghostsInfo["Ghost_3"].second]->objectName() == "Special_Dot") {
        mLabels[setGhostsMovement.ghostsInfo["Ghost_3"].first][setGhostsMovement.ghostsInfo["Ghost_3"].second]->setText("•");
    }
    if(mLabels[setGhostsMovement.ghostsInfo["Ghost_3"].first][setGhostsMovement.ghostsInfo["Ghost_3"].second]->objectName() == "") {
        mLabels[setGhostsMovement.ghostsInfo["Ghost_3"].first][setGhostsMovement.ghostsInfo["Ghost_3"].second]->setText("•");
        mLabels[setGhostsMovement.ghostsInfo["Ghost_3"].first][setGhostsMovement.ghostsInfo["Ghost_3"].second]->setText("");
    }

    if(mLabels[setGhostsMovement.ghostsInfo["Ghost_4"].first][setGhostsMovement.ghostsInfo["Ghost_4"].second]->objectName() == "Dot" || mLabels[setGhostsMovement.ghostsInfo["Ghost_4"].first][setGhostsMovement.ghostsInfo["Ghost_4"].second]->objectName() == "Special_Dot") {
        mLabels[setGhostsMovement.ghostsInfo["Ghost_4"].first][setGhostsMovement.ghostsInfo["Ghost_4"].second]->setText("•");
    }
    if(mLabels[setGhostsMovement.ghostsInfo["Ghost_4"].first][setGhostsMovement.ghostsInfo["Ghost_4"].second]->objectName() == "") {
        mLabels[setGhostsMovement.ghostsInfo["Ghost_4"].first][setGhostsMovement.ghostsInfo["Ghost_4"].second]->setText("•");
        mLabels[setGhostsMovement.ghostsInfo["Ghost_4"].first][setGhostsMovement.ghostsInfo["Ghost_4"].second]->setText("");
    }
}

void Labels::moveGhosts()
{
    setGhostsMovement.getMoveablePos();
    setGhosts();
    if(mLabels[setGhostsMovement.ghostsInfo["Ghost_1"].first][setGhostsMovement.ghostsInfo["Ghost_1"].second]->objectName() == "Pac_Man") {
        mLabels[setGhostsMovement.ghostsInfo["Ghost_1"].first][setGhostsMovement.ghostsInfo["Ghost_1"].second]->setText("");
        emit gameOver();
    }
    if(mLabels[setGhostsMovement.ghostsInfo["Ghost_2"].first][setGhostsMovement.ghostsInfo["Ghost_2"].second]->objectName() == "Pac_Man") {
        mLabels[setGhostsMovement.ghostsInfo["Ghost_2"].first][setGhostsMovement.ghostsInfo["Ghost_2"].second]->setText("");
        emit gameOver();
    }
    if(mLabels[setGhostsMovement.ghostsInfo["Ghost_3"].first][setGhostsMovement.ghostsInfo["Ghost_3"].second]->objectName() == "Pac_Man") {
        mLabels[setGhostsMovement.ghostsInfo["Ghost_3"].first][setGhostsMovement.ghostsInfo["Ghost_3"].second]->setText("");
        emit gameOver();
    }
    if(mLabels[setGhostsMovement.ghostsInfo["Ghost_4"].first][setGhostsMovement.ghostsInfo["Ghost_4"].second]->objectName() == "Pac_Man") {
        mLabels[setGhostsMovement.ghostsInfo["Ghost_4"].first][setGhostsMovement.ghostsInfo["Ghost_4"].second]->setText("");
        emit gameOver();
    }
}

void Labels::setTerrifiedGhosts()
{
    mLabels[setGhostsMovement.ghostsInfo["Ghost_1"].first][setGhostsMovement.ghostsInfo["Ghost_1"].second]->setPixmap(QPixmap(":/terrified_ghost.png").scaled(pixmapWidth, pixmapHeight, Qt::KeepAspectRatio));
    mLabels[setGhostsMovement.ghostsInfo["Ghost_2"].first][setGhostsMovement.ghostsInfo["Ghost_2"].second]->setPixmap(QPixmap(":/terrified_ghost.png").scaled(pixmapWidth, pixmapHeight, Qt::KeepAspectRatio));
    mLabels[setGhostsMovement.ghostsInfo["Ghost_3"].first][setGhostsMovement.ghostsInfo["Ghost_3"].second]->setPixmap(QPixmap(":/terrified_ghost.png").scaled(pixmapWidth, pixmapHeight, Qt::KeepAspectRatio));
    mLabels[setGhostsMovement.ghostsInfo["Ghost_4"].first][setGhostsMovement.ghostsInfo["Ghost_4"].second]->setPixmap(QPixmap(":/terrified_ghost.png").scaled(pixmapWidth, pixmapHeight, Qt::KeepAspectRatio));

    updateExternLabels();
}
