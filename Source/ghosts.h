#ifndef GHOSTS_H
#define GHOSTS_H

#include <QVector>

class Ghosts
{
public:
    Ghosts();

    QVector<int> ghostsRows;
    QVector<int> ghostsCols;
    QVector<QVector<int>> moveablePos;

    void getGhostsPos();
    void moveGhostsPos();
    void findBestMove();
    void chooseBestMove();

private:
    void getMoveablePos();
};

#endif // GHOSTS_H
