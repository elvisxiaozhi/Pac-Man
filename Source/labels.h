#ifndef LABELS_H
#define LABELS_H

#include <QLabel>

class Labels
{
public:
    Labels();

    QLabel *mLabels[13][30];
    void setLabels();
    void setLetters();
    void setBorders();
};

#endif // LABELS_H
