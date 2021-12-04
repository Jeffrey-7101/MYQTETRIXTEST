#ifndef QTETRIXWINDOW_H
#define QTETRIXWINDOW_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>

#include "qtetrixboard.h"

QT_BEGIN_NAMESPACE
class QLCDNumber;
class QLabel;
class QPushButton;
QT_END_NAMESPACE
class TetrixBoard;

class QTetrixWindow: public QWidget
{
    Q_OBJECT;
public:
    explicit QTetrixWindow(QWidget *parent= nullptr);


private:

    QTetrixBoard *board;

    QLabel *createLabel(const QString &text);
    QLabel *nextPieceLabel;
    QLCDNumber *scoreLcd;
    QLCDNumber *levelLcd;
    QLCDNumber *linesLcd;
    //QLabel *dificultLcd;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;
    int dificultad;

public slots:
    void easy(int d);
    void normal(int d);
    void bastard(int d);

   // void dificultSlot(int d);//set Dificult
signals:
    void dificultSignal(int dificult);
    //void normalSignal();
    //void bastardSignal();

};

#endif // QTETRIXWINDOW_H
