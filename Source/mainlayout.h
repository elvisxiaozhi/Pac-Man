#ifndef MAINLAYOUT_H
#define MAINLAYOUT_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>

class MainLayout : public QMainWindow
{
    Q_OBJECT

public:
    MainLayout(QWidget *parent = 0);
    ~MainLayout();

private:
    QWidget *mainInterface;
    QGridLayout *gLayout;
    QLabel *mLabels[10][10];

    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINLAYOUT_H
