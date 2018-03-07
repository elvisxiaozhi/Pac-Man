#ifndef MAINLAYOUT_H
#define MAINLAYOUT_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include "labels.h"

class MainLayout : public QMainWindow
{
    Q_OBJECT

public:
    MainLayout(QWidget *parent = 0);
    ~MainLayout();

private:
    QWidget *mainInterface;
    QGridLayout *gLayout;

    void keyPressEvent(QKeyEvent *event);

    Labels pixelLabels;
};

#endif // MAINLAYOUT_H
