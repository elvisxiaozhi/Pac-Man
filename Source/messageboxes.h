#ifndef MESSAGEBOXES_H
#define MESSAGEBOXES_H

#include <QMessageBox>

class MessageBoxes : public QObject
{
    Q_OBJECT
public:
    MessageBoxes();

    void showPlayAgainMsBox();

    QMessageBox playAgainMsBox;

signals:
    void playAgain();
};

#endif // MESSAGEBOXES_H
