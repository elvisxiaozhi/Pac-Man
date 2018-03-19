#include "ghosts.h"
#include "labels.h"
#include <QDebug>

Ghosts::Ghosts()
{
}

void Ghosts::getGhostsPos()
{
    ghostsRows.clear();
    ghostsCols.clear();
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            if(pixelLabels[i][j].objectName() == "Ghost") {
                ghostsRows.push_back(i);
                ghostsCols.push_back(j);
            }
        }
    }
    qDebug() << "ghosts pos: " << ghostsRows << ghostsCols;

    getMoveablePos();
    moveGhostsPos();
}

void Ghosts::moveGhostsPos()
{
    for(int i = 0; i < 4; i++) {
        moveablePos[i].erase(std::remove_if(moveablePos[i].begin(), moveablePos[i].end(), [](int i) {return i == 0;}), moveablePos[i].end());
    }
    qDebug() << "Removed unable moves: "  << moveablePos;

    findBestMove();
    chooseBestMove();

    for(int i =  0; i < 4; i++) {
        if(moveablePos[i][0] == 1) {
            ghostsRows[i] -= 1;
        }
        if(moveablePos[i][0] == 2) {
            ghostsRows[i] += 1;
        }
        if(moveablePos[i][0] == 3) {
            ghostsCols[i] -= 1;
        }
        if(moveablePos[i][0] == 4) {
            ghostsCols[i] += 1;
        }
    }
    qDebug() << "After ghosts pos: " << ghostsRows << ghostsCols;
}

void Ghosts::findBestMove()
{
    int Yellow_Ball_Row, Yellow_Ball_Col;
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            if(pixelLabels[i][j].objectName() == "Yellow_Ball") {
                Yellow_Ball_Row = i;
                Yellow_Ball_Col = j;
            }
        }
    }

    for(int i = 0; i < 4; i++) {
        if(Yellow_Ball_Row <= ghostsRows[i]) {
            if(std::find(moveablePos[i].begin(), moveablePos[i].begin(), 1) != moveablePos[i].end()) {
                moveablePos[i].push_back(1);
                if(Yellow_Ball_Col < ghostsCols[i]) {
                    if(std::find(moveablePos[i].begin(), moveablePos[i].begin(), 3) != moveablePos[i].end()) {
                        moveablePos[i].push_back(3);
                    }
                }
                if(Yellow_Ball_Col > ghostsCols[i]) {
                    if(std::find(moveablePos[i].begin(), moveablePos[i].begin(), 4) != moveablePos[i].end()) {
                        moveablePos[i].push_back(4);
                    }
                }
            }
        }
        else {
            if(std::find(moveablePos[i].begin(), moveablePos[i].begin(), 2) != moveablePos[i].end()) {
                moveablePos[i].push_back(2);
                if(Yellow_Ball_Col < ghostsCols[i]) {
                    if(std::find(moveablePos[i].begin(), moveablePos[i].begin(), 3) != moveablePos[i].end()) {
                        moveablePos[i].push_back(3);
                    }
                }
                if(Yellow_Ball_Col > ghostsCols[i]) {
                    if(std::find(moveablePos[i].begin(), moveablePos[i].begin(), 4) != moveablePos[i].end()) {
                        moveablePos[i].push_back(4);
                    }
                }
            }
        }
    }
    qDebug() << "added new best moves: "<< moveablePos;
}

void Ghosts::chooseBestMove()
{
    for(int i = 0; i < 4; i++) {
        int choice = rand() % moveablePos[i].size();
        int move = moveablePos[i][choice];
        moveablePos[i].clear();
        moveablePos[i].push_back(move);
    }
    qDebug() << "the best choice: " << moveablePos;
}

void Ghosts::getMoveablePos()
{
    moveablePos.clear();
    moveablePos.resize(4);
    for(int i = 0; i < 4; i++) {
        moveablePos[i].resize(4);
    }
    for(int i = 0; i < 4; i++) {
        if(pixelLabels[ghostsRows[i] - 1][ghostsCols[i]].objectName() != "Barrier") { //up
            moveablePos[i][0] = 1;
        }
        if(pixelLabels[ghostsRows[i] + 1][ghostsCols[i]].objectName() != "Barrier") { //down
            moveablePos[i][1] = 2;
        }
        if(pixelLabels[ghostsRows[i]][ghostsCols[i] - 1].objectName() != "Barrier") { //left
            moveablePos[i][2] = 3;
        }
        if(pixelLabels[ghostsRows[i]][ghostsCols[i] + 1].objectName() != "Barrier") { //right
            moveablePos[i][3] = 4;
        }
    }
    qDebug() << "Got possiable moves: " << moveablePos;
}
