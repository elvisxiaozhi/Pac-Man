#ifndef LABELS_H
#define LABELS_H

#include <QLabel>

extern QLabel **pixelLabels;

class Labels
{
public:
    Labels();

    QLabel *mLabels[13][30];

    void updateLabels();
    void setBarriers();
    void setDots();
    void setYellowBall();
    void moveYellowBall(int);

private:
    int currentRow, currentCol;

    void setEmptyPlaces();
    void updateExternLabels();
    void getCurrentYellowBallPos();
    void moveCurrentYellowBall(int, int);
};

#endif // LABELS_H
