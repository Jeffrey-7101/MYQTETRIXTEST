#ifndef QTETRIXWINDOW_H
#define QTETRIXWINDOW_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
#include <QMessageBox>


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
    QTetrixBoard *board;

   /* int getX()const{
        return this->aux;
    }*/
private:

    QLabel *createLabel(const QString &text);
    QLabel *nextPieceLabel;
    QLabel *difcultLabel;
    QLCDNumber *scoreLcd;
    QLCDNumber *levelLcd;
    QLCDNumber *linesLcd;

    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;
    int dificultadWindow=5;
   // int aux;



public slots:
    void easy();
    void normal();
    void bastard();
    void gameOver();

   // void dificultSlot(int d);//set Dificult
signals:
    void dificultSignal(int dificult);
    //void normalSignal();
    //void bastardSignal();

};

#endif // QTETRIXWINDOW_H
