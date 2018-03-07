#include "mainlayout.h"
#include <QDebug>
#include <QKeyEvent>

MainLayout::MainLayout(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Pac-Man(Made by Theodore)");
    mainInterface = new QWidget(this);
    setCentralWidget(mainInterface);
    gLayout = new QGridLayout(mainInterface);
    mainInterface->setLayout(gLayout);
    gLayout->setSpacing(0);
    setLabels();
    setLetters();
    setBorders();
}

MainLayout::~MainLayout()
{

}

void MainLayout::setLabels()
{
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 30; j++) {
            mLabels[i][j] = new QLabel(mainInterface);
            mLabels[i][j]->setText(QString::number(i) + QString::number(j)); //用于调试的时候用
            mLabels[i][j]->setAlignment(Qt::AlignCenter);
            mLabels[i][j]->setFixedSize(25, 25);
            gLayout->addWidget(mLabels[i][j], i, j);
        }
    }
}

void MainLayout::setLetters()
{
    for(int i = 0; i < 5; i++) {
        mLabels[2][5 + i]->setStyleSheet("QLabel {background-color: red/*; border: 1px solid blue;*/}");
        mLabels[2][5 + i]->setText("");
    }
    for(int i = 0; i < 7; i++) {
        mLabels[2 + i][7]->setStyleSheet("QLabel {background-color: red}");
        mLabels[2 + i][7]->setText("");
        mLabels[2 + i][11]->setStyleSheet("QLabel {background-color: yellow}");
        mLabels[2 + i][11]->setText("");
        mLabels[2 + i][14]->setStyleSheet("QLabel {background-color: yellow}");
        mLabels[2 + i][14]->setText("");
        mLabels[2 + i][16]->setStyleSheet("QLabel {background-color: blue}");
        mLabels[2 + i][16]->setText("");
        mLabels[2 + i][21]->setStyleSheet("QLabel {background-color: green}");
        mLabels[2 + i][21]->setText("");
        mLabels[2 + i][24]->setStyleSheet("QLabel {background-color: green}");
        mLabels[2 + i][24]->setText("");
    }
    for(int i = 0; i < 2; i++) {
        mLabels[5][12 + i]->setStyleSheet("QLabel {background-color: yellow}");
        mLabels[5][12 + i]->setText("");
        mLabels[2][22 + i]->setStyleSheet("QLabel {background-color: green}");
        mLabels[2][22 + i]->setText("");
        mLabels[8][22 + i]->setStyleSheet("QLabel {background-color: green}");
        mLabels[8][22 + i]->setText("");
    }
    for(int i = 0; i < 3; i++) {
        mLabels[2][17 + i]->setStyleSheet("QLabel {background-color: blue}");
        mLabels[2][17 + i]->setText("");
        mLabels[5][17 + i]->setStyleSheet("QLabel {background-color: blue}");
        mLabels[5][17 + i]->setText("");
        mLabels[8][17 + i]->setStyleSheet("QLabel {background-color: blue}");
        mLabels[8][17 + i]->setText("");
    }
}

void MainLayout::setBorders()
{
    for(int i = 0; i < 30; i++) {
        mLabels[0][0 + i]->setStyleSheet("QLabel {background-color: black; border-top: 2px solid blue; border-bottom: 2px solid blue;}");
        mLabels[0][0 + i]->setText("");
        //“12（第一位数）”应随着row的数量而变化
        mLabels[12][0 + i]->setStyleSheet("QLabel {background-color: black; border-top: 2px solid blue; border-bottom: 2px solid blue;}");
        mLabels[12][0 + i]->setText("");
    }
    for(int i = 0; i < 13; i++) {
        mLabels[0 + i][0]->setStyleSheet("QLabel {background-color: black; border-left: 2px solid blue; border-right: 2px solid blue;}");
        mLabels[0 + i][0]->setText("");
        mLabels[0 + i][29]->setStyleSheet("QLabel {background-color: black; border-left: 2px solid blue; border-right: 2px solid blue;}");
        mLabels[0 + i][29]->setText("");
    }
    for(int i = 0; i < 2; i++) {
        mLabels[10 + i][10]->setStyleSheet("QLabel {background-color: black; border-left: 2px solid blue; border-right: 2px solid blue;}");
        mLabels[10 + i][10]->setText("");
        mLabels[10 + i][24]->setStyleSheet("QLabel {background-color: black; border-left: 2px solid blue; border-right: 2px solid blue;}");
        mLabels[10 + i][24]->setText("");
        mLabels[10][2 + i]->setStyleSheet("QLabel {background-color: black; border-left: 2px solid blue; border-right: 2px solid blue;}");
        mLabels[10][2 + i]->setText("");
    }
    for(int i = 0; i < 4; i++) {
        mLabels[10][5 + i]->setStyleSheet("QLabel {background-color: black; border-left: 2px solid blue; border-right: 2px solid blue;}");
        mLabels[10][5 + i]->setText("");
    }
    for(int i = 0; i < 5; i++) {
        mLabels[8][1 + i]->setStyleSheet("QLabel {background-color: black; border-top: 2px solid blue; border-bottom: 2px solid blue;}");
        mLabels[8][1 + i]->setText("");
    }
}

void MainLayout::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Right)
        qDebug() << "U";
}
