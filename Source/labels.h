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
    void setBorders();
    void setYellowBall();
    void moveYellowBall(int);

private:
    int currentRow, currentCol;
    void getCurrentYellowBallPos();
};

#endif // LABELS_H
