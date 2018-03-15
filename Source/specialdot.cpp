#include "specialdot.h"
#include <QDebug>
#include "labels.h"

SpecialDot::SpecialDot()
{
//    generateFiveDots();
}

void SpecialDot::generateFiveDots()
{
    int row = 0, col = 0;
//    qDebug() << mLabels->dotCols.size();
    for(int i = 0; i < 5; i++) {
        row = rand() % 13;
        col = rand() % 30;
        Rows.push_back(row);
        Cols.push_back(col);
    }
    qDebug() << Rows << Cols;
}

void SpecialDot::testing(int a)
{
    qDebug() << a << "Done";
}
