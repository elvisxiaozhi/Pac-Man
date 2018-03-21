#ifndef LABELS_H
#define LABELS_H

#include <QLabel>
#include <QMap>
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
    void setPacMan();
    void setGhosts();
    void moveYellowBall(int);

private:
    Ghosts setGhostsMovement;
    QVector<int> beneathGhostsRows;
    QVector<int> beneathGhostsCols;
    QVector<QString> beneathGhostsObjectsNames;
    QMap<std::pair<int, int>, QString> beneathGhosts;

    int pixmapWidth, pixmapHeight;
    int currentRow, currentCol;

    void setEmptyPlaces();
    void updateExternLabels();
    void getCurrentYellowBallPos();
    void moveCurrentYellowBall(int, int);
    void getBeneathGhostsInfo();

signals:
    void gameOver();
    void ateSpecialDot();

public slots:
    void resetBeneathGhosts();
    void moveGhosts();
    void setTerrifiedGhosts();
};

#endif // LABELS_H
