#ifndef MAINLAYOUT_H
#define MAINLAYOUT_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QTimer>
#include "labels.h"
#include "dots.h"
#include "messageboxes.h"

class MainLayout : public QMainWindow
{
    Q_OBJECT

public:
    MainLayout(QWidget *parent = 0);
    ~MainLayout();

private:
    int arrowKey;
    int dotNumber;
    int countdownTime;
    int iterateTimes;

    QWidget *mainInterface;
    QGridLayout *gLayout;
    QTimer *setTimer;
    QTimer *ghostsTimer;
    QTimer *countdownTimer;

    void keyPressEvent(QKeyEvent *);
    bool checkWin();

    Labels setLabels;
    Dots setDots;
    MessageBoxes setMsBox;

signals:
    void terrifiedGhosts();
    void effectGone();

private slots:
    void afterTimeout();
    void playAgain();
    void gameOver();
    void specialDotEffect();
    void afterCountingDown();
};

#endif // MAINLAYOUT_H
