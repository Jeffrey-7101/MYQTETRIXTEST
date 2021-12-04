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
private:
    QLabel *createLabel(const QString &text);

    QTetrixWindow *window;
    QTetrixBoard *board;

    QPushButton *easyMode;
    QPushButton *normalMode;
    QPushButton *bastardMode;

public slots:
    void closeWindow(){
        this->close();
    }
};

#endif // DIFICULTWINDOW_H
