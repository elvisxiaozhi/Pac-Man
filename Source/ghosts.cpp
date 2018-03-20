#include "ghosts.h"
#include "labels.h"
#include <QDebug>

Ghosts::Ghosts()
{
    setGhostsInfo();
}

void Ghosts::moveGhostsPos(QString ghostName, int ghostNumber)
{
    if(moveablePos[ghostNumber][0] == 1) {
        ghostsInfo[ghostName].first -= 1;
    }
    if(moveablePos[ghostNumber][0] == 2) {
        ghostsInfo[ghostName].first += 1;
    }
    if(moveablePos[ghostNumber][0] == 3) {
        ghostsInfo[ghostName].second -= 1;
    }
    if(moveablePos[ghostNumber][0] == 4) {
        ghostsInfo[ghostName].second += 1;
    }
}

void Ghosts::chooseBestMove()
{
    for(int i = 0; i < 4; i++) {
        int choice = rand() % moveablePos[i].size();
        int move = moveablePos[i][choice];
        moveablePos[i].clear();
        moveablePos[i].push_back(move);
    }
}

void Ghosts::setGhostsInfo()
{
    ghostsInfo["Ghost_1"] = std::make_pair(1, 1);
    ghostsInfo["Ghost_2"] = std::make_pair(1, 28);
    ghostsInfo["Ghost_3"] = std::make_pair(11, 1);
    ghostsInfo["Ghost_4"] = std::make_pair(11, 28);
}


void Ghosts::getMoveablePos()
{
    moveablePos.clear();
    moveablePos.resize(4);
    for(int i = 0; i < 4; i++) {
        moveablePos[i].resize(4);
    }
    checkMoveablePos("Ghost_1", 0);
    checkMoveablePos("Ghost_2", 1);
    checkMoveablePos("Ghost_3", 2);
    checkMoveablePos("Ghost_4", 3);

    for(int i = 0; i < moveablePos.size(); i++) {
        moveablePos[i].erase(std::remove_if(moveablePos[i].begin(), moveablePos[i].end(), [](int i) {return i == 0;}), moveablePos[i].end());
    }

    int Pac_Man_Row, Pac_Man_Col;
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            if(pixelLabels[i][j].objectName() == "Pac_Man") {
                Pac_Man_Row = i;
                Pac_Man_Col = j;
            }
        }
    }

    moveToPacMan("Ghost_1", 0, Pac_Man_Row, Pac_Man_Col);
    moveToPacMan("Ghost_2", 1, Pac_Man_Row, Pac_Man_Col);
    moveToPacMan("Ghost_3", 2, Pac_Man_Row, Pac_Man_Col);
    moveToPacMan("Ghost_4", 3, Pac_Man_Row, Pac_Man_Col);

    chooseBestMove();

    emit ghostsOnTheMove();

    moveGhostsPos("Ghost_1", 0);
    moveGhostsPos("Ghost_2", 1);
    moveGhostsPos("Ghost_3", 2);
    moveGhostsPos("Ghost_4", 3);
}

void Ghosts::moveToPacMan(QString ghostName, int ghostNumber, int Pac_Man_Row, int Pac_Man_Col)
{
    if(Pac_Man_Row <= ghostsInfo[ghostName].first) {
        if(std::find(moveablePos[ghostNumber].begin(), moveablePos[ghostNumber].end(), 1) != moveablePos[ghostNumber].end()) {
            moveablePos[ghostNumber].push_back(1);
            if(Pac_Man_Col < ghostsInfo[ghostName].second) {
                if(std::find(moveablePos[ghostNumber].begin(), moveablePos[ghostNumber].end(), 3) != moveablePos[ghostNumber].end()) {
                    moveablePos[ghostNumber].push_back(3);
                }
            }
            if(Pac_Man_Col > ghostsInfo[ghostName].second) {
                if(std::find(moveablePos[ghostNumber].begin(), moveablePos[ghostNumber].end(), 4) != moveablePos[ghostNumber].end()) {
                    moveablePos[ghostNumber].push_back(4);
                }
            }
        }
    }
    else {
        if(std::find(moveablePos[ghostNumber].begin(), moveablePos[ghostNumber].end(), 2) != moveablePos[ghostNumber].end()) {
            moveablePos[ghostNumber].push_back(2);
            if(Pac_Man_Col < ghostsInfo[ghostName].second) {
                if(std::find(moveablePos[ghostNumber].begin(), moveablePos[ghostNumber].end(), 3) != moveablePos[ghostNumber].end()) {
                    moveablePos[ghostNumber].push_back(3);
                }
            }
            if(Pac_Man_Col > ghostsInfo[ghostName].second) {
                if(std::find(moveablePos[ghostNumber].begin(), moveablePos[ghostNumber].end(), 4) != moveablePos[ghostNumber].end()) {
                    moveablePos[ghostNumber].push_back(4);
                }
            }
        }
    }
}

void Ghosts::checkMoveablePos(QString ghostName, int ghostNumber)
{
    if(pixelLabels[ghostsInfo[ghostName].first - 1][ghostsInfo[ghostName].second].objectName() != "Barrier") {
        moveablePos[ghostNumber][0] = 1;
    }
    if(pixelLabels[ghostsInfo[ghostName].first + 1][ghostsInfo[ghostName].second].objectName() != "Barrier") {
        moveablePos[ghostNumber][1] = 2;
    }
    if(pixelLabels[ghostsInfo[ghostName].first][ghostsInfo[ghostName].second - 1].objectName() != "Barrier") {
        moveablePos[ghostNumber][2] = 3;
    }
    if(pixelLabels[ghostsInfo[ghostName].first][ghostsInfo[ghostName].second + 1].objectName() != "Barrier") {
        moveablePos[ghostNumber][3] = 4;
    }
}
