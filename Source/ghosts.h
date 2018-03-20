#ifndef GHOSTS_H
#define GHOSTS_H

#include <QVector>
#include <QMap>
#include <QObject>

class Ghosts : public QObject
{
    Q_OBJECT
public:
    Ghosts();

    QMap<QString, std::pair<int, int>> ghostsInfo;
    QVector<QVector<int>> moveablePos;

    void getMoveablePos();
    void moveGhostsPos(QString, int);
    void findBestMove();
    void chooseBestMove();
    void moveToPacMan(QString, int, int, int);

private:
    void setGhostsInfo();
    void checkMoveablePos(QString, int);

signals:
    void ghostsOnTheMove();
};

#endif // GHOSTS_H
