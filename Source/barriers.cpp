#include "barriers.h"
#include "labels.h"
#include <QDebug>

Barriers::Barriers()
{
    makeBarriers();
}

void Barriers::makeBarriers()
{
    for(int i = 0; i < 2; i++) {
        pixelLabels[5][12 + i].setObjectName("Yellow_Letter");
        pixelLabels[2][22 + i].setObjectName("Green_Letter");
        pixelLabels[8][22 + i].setObjectName("Green_Letter");
        pixelLabels[10 + i][10].setObjectName("Road_Barrier");
        pixelLabels[10 + i][24].setObjectName("Road_Barrier");
        pixelLabels[10][2 + i].setObjectName("Road_Barrier");
        pixelLabels[3][27 + i].setObjectName("Road_Barrier");
        pixelLabels[5][4 + i].setObjectName("Road_Barrier");
    }
    for(int i = 0; i < 3; i++) {
        pixelLabels[2][17 + i].setObjectName("Blue_Letter");
        pixelLabels[5][17 + i].setObjectName("Blue_Letter");
        pixelLabels[8][17 + i].setObjectName("Blue_Letter");
    }
    for(int i = 0; i < 4; i++) {
        pixelLabels[10][5 + i].setObjectName("Road_Barrier");
    }
    for(int i = 0; i < 5; i++) {
        pixelLabels[2][5 + i].setObjectName("Red_Letter");
        pixelLabels[8][1 + i].setObjectName("Road_Barrier");
        pixelLabels[10][12 + i].setObjectName("Road_Barrier");
        pixelLabels[10][18 + i].setObjectName("Road_Barrier");
        pixelLabels[6 + i][26].setObjectName("Road_Barrier");
        pixelLabels[2 + i][2].setObjectName("Road_Barrier");
    }
    for(int i = 0; i < 7; i++) {
        pixelLabels[2 + i][7].setObjectName("Red_Letter");
        pixelLabels[2 + i][11].setObjectName("Yellow_Letter");
        pixelLabels[2 + i][14].setObjectName("Yellow_Letter");
        pixelLabels[2 + i][16].setObjectName("Blue_Letter");
        pixelLabels[2 + i][21].setObjectName("Green_Letter");
        pixelLabels[2 + i][24].setObjectName("Green_Letter");
    }
}
