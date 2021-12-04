#ifndef DIFICULTWINDOW_H
#define DIFICULTWINDOW_H

#include <QObject>
#include <QWidget>
#include "qtetrixwindow.h"



class DificultWindow : public QWidget
{
    Q_OBJECT
public:
    explicit DificultWindow(QWidget *parent = nullptr);
   // QTetrixBoard *board;
    QTetrixWindow *window;

private:
    QLabel *createLabel(const QString &text);


    //QTetrixBoard *board;

    QPushButton *easyMode;
    QPushButton *normalMode;
    QPushButton *bastardMode;
    void showWindonMain();
public slots:
    void closeWindow(){
        this->close();
    }
};

#endif // DIFICULTWINDOW_H
