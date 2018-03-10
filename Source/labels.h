#ifndef LABELS_H
#define LABELS_H

#include <QLabel>

class Labels
{
public:
    Labels();

    QLabel *mLabels[13][30];

    void setLabels();
    void setLetters();
    void setYellowBall();
    void moveYellowBall(int);

private:
    int currentRow, currentCol;

    void markBarriers();
    void setBarriers();
    void getCurrentYellowBallPos();
    void moveCurrentYellowBall(int, int);
};

#endif // LABELS_H
