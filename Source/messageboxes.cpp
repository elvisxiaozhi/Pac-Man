#include "messageboxes.h"

MessageBoxes::MessageBoxes()
{

}

void MessageBoxes::showPlayAgainMsBox()
{
    playAgainMsBox.setText("Do you want to play it again?");
    playAgainMsBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    playAgainMsBox.setDefaultButton(QMessageBox::No);

    playAgainMsBox.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    playAgainMsBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    playAgainMsBox.setStyleSheet("QLabel{min-width: 200px;}");
    int ret = playAgainMsBox.exec();

    switch (ret) {
    case QMessageBox::Yes:
        emit playAgain();
        break;
    case QMessageBox::No:
        playAgainMsBox.close();
        break;
    default:
        break;
    }
}
