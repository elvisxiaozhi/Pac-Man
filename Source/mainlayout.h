#ifndef MAINLAYOUT_H
#define MAINLAYOUT_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QTimer>
#include "labels.h"
#include "dots.h"

class MainLayout : public QMainWindow
{
    Q_OBJECT

public:
    MainLayout(QWidget *parent = 0);
    ~MainLayout();

private:
    int arrowKey;

    QWidget *mainInterface;
    QGridLayout *gLayout;
    QTimer *setTimer;

    void keyPressEvent(QKeyEvent *);

    Labels setLabels;
    Dots setDots;

private slots:
    void afterTimeout();
};

#endif // MAINLAYOUT_H
