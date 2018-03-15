#ifndef SPECIALDOT_H
#define SPECIALDOT_H

#include <QVector>
#include <QObject>

class SpecialDot : public QObject
{
    Q_OBJECT
public:
    SpecialDot();
    QVector<int> Rows;
    QVector<int> Cols;

private:
    void generateFiveDots();

public slots:
    void testing(int);
};

#endif // SPECIALDOT_H
