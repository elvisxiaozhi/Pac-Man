#include "mainlayout.h"
#include <QDebug>
#include <QKeyEvent>

MainLayout::MainLayout(QWidget *parent)
    : QMainWindow(parent)
{
    mainInterface = new QWidget(this);
    setCentralWidget(mainInterface);
    gLayout = new QGridLayout(mainInterface);
    mainInterface->setLayout(gLayout);

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            mLabels[i][j] = new QLabel(mainInterface);
            mLabels[i][j]->setText(QString::number(j + 10 * i));
            gLayout->addWidget(mLabels[i][j], i, j);
        }
    }
}

MainLayout::~MainLayout()
{

}

void MainLayout::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Right)
        qDebug() << "U";
}
