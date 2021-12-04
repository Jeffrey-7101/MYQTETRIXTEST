#include <QCoreApplication>
#include <QApplication>
#include <QDebug>


#include "dificultwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DificultWindow window;
    window.show();

   /* static constexpr int coordsTable[8][4][2] = {
            { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } },
            { { 0, -1 },  { 0, 0 },   { -1, 0},   { -1, 1} },
            { { 0, -1 },  { 0, 0 },   { 1, 0 },   { 1, 1 } },
            { { 0, -1 },  { 0, 0 },   { 0, 1 },   { 0, 2 } },
            { { -1, 0 },  { 0, 0 },   { 1, 0 },   { 0, 1 } },
            { { 0, 0  },  { 1, 0 },   { 0, 1 },   { 1, 1 } },
            { { -1, -1},  { 0, -1},   { 0, 0 },   { 0, 1 } },
            { { 1, -1 },  { 0, -1},   { 0, 0 },   { 0, 1 } }
        };

    qDebug()<<"Indice 1";

        for (int i = 0; i < 4 ; i++) {
            for (int j = 0; j < 2; ++j)
                 qDebug()<< coordsTable[1][i][j]<<"\n";
        }
    qDebug()<<"Indice 2";
    for (int i = 0; i < 4 ; i++) {
        for (int j = 0; j < 2; ++j)
             qDebug()<< coordsTable[2][i][j]<<"\n";
    }
    qDebug()<<"Indice 3";
    for (int i = 0; i < 4 ; i++) {
        for (int j = 0; j < 2; ++j)
             qDebug()<< coordsTable[3][i][j]<<"\n";
    }
    qDebug()<<"Indice 4";
    for (int i = 0; i < 4 ; i++) {
        for (int j = 0; j < 2; ++j)
             qDebug()<< coordsTable[4][i][j]<<"\n";
    }
    qDebug()<<"Indice 5";
    for (int i = 0; i < 4 ; i++) {
        for (int j = 0; j < 2; ++j)
             qDebug()<< coordsTable[5][i][j]<<"\n";
    }
    qDebug()<<"Indice 6";
    for (int i = 0; i < 4 ; i++) {
        for (int j = 0; j < 2; ++j)
             qDebug()<< coordsTable[6][i][j]<<"\n";
    }
    qDebug()<<"Indice 7";
    for (int i = 0; i < 4 ; i++) {
        for (int j = 0; j < 2; ++j)
             qDebug()<< coordsTable[7][i][j]<<"\n";
    }
    qDebug()<<"Indice 8";
    for (int i = 0; i < 4 ; i++) {
        for (int j = 0; j < 2; ++j)
             qDebug()<< coordsTable[8][i][j]<<"\n";
    }*/
    return a.exec();
   // return 0;
}
