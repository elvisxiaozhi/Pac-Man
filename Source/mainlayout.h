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

    QWidget *mainInterface;
    QGridLayout *gLayout;
    QTimer *setTimer;

    void keyPressEvent(QKeyEvent *);
    bool checkWin();

    Labels setLabels;
    Dots setDots;
    MessageBoxes setMsBox;

private slots:
    void afterTimeout();
    void playAgain();
    void gameOver();
};

#endif // MAINLAYOUT_H
