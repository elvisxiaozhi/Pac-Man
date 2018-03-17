#include "dots.h"
#include "labels.h"
#include "barriers.h"
#include <QDebug>

Dots::Dots()
{
    Barriers mBarriers;
}

void Dots::generateFiveSpecialDots()
{
    for(int i = 0; i < 5; i++) {
        while(true) {
            int row = rand() % 13;
            int col = rand() % 30;
            if(pixelLabels[row][col].objectName() == "") {
                pixelLabels[row][col].setObjectName("Special_Dot");
                break;
            }
        }
    }
}
