#include "mainlayout.h"
#include <QApplication>
#include <cstdlib>
#include "labels.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);

    //it needs to be put after QApplication
    for(int i = 0; i < 13; i++) {
        pixelLabels[i] = new QLabel[30];
    }

    MainLayout w;
    w.show();

    return a.exec();
}
