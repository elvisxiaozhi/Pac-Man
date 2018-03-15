#ifndef LABELS_H
#define LABELS_H

#include <QLabel>
#include "specialdot.h"

class Labels : public QObject
{
    Q_OBJECT
public:
    Labels();

    QLabel *mLabels[13][30];

    void setLabels();
    void setYellowBall();
    void moveYellowBall(int);

    QVector<int> dotRows;
    QVector<int> dotCols;

private:
    int currentRow, currentCol;

    SpecialDot mDots;

    void markBarriers();
    void setBarriers();
    void setDots();
    void getCurrentYellowBallPos();
    void moveCurrentYellowBall(int, int);

signals:
    void mLabelsChanged(int);
};

#endif // LABELS_H
