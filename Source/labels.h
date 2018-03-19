#ifndef LABELS_H
#define LABELS_H

#include <QLabel>
#include "ghosts.h"

extern QLabel **pixelLabels;

class Labels : public QObject
{
    Q_OBJECT
public:
    Labels();

    QLabel *mLabels[13][30];

    void updateLabels();
    void setBarriers();
    void setDots();
    void setYellowBall();
    void setGhosts();
    void moveYellowBall(int);

private:
    Ghosts setGhostsMovement;
    QLabel beneathGhosts[4][4];

    int currentRow, currentCol;

    void setEmptyPlaces();
    void updateExternLabels();
    void getCurrentYellowBallPos();
    void moveCurrentYellowBall(int, int);

signals:
    void gameOver();
};

#endif // LABELS_H
