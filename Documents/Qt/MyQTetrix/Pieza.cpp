#include "Pieza.h"
#include <QtCore>

void Pieza::setRandomShape(){
    setShape(Forma(QRandomGenerator::global()->bounded(7)+1));//+1 para evitar el 0 que es la forma nula(sinForma)
}
void Pieza::setShape(Forma forma){
    static constexpr int coordsTable[8][4][2] = {
            { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } },
            { { 0, -1 },  { 0, 0 },   { -1, 0},   { -1, 1} },
            { { 0, -1 },  { 0, 0 },   { 1, 0 },   { 1, 1 } },
            { { 0, -1 },  { 0, 0 },   { 0, 1 },   { 0, 2 } },
            { { -1, 0 },  { 0, 0 },   { 1, 0 },   { 0, 1 } },
            { { 0, 0  },  { 1, 0 },   { 0, 1 },   { 1, 1 } },
            { { -1, -1},  { 0, -1},   { 0, 0 },   { 0, 1 } },
            { { 1, -1 },  { 0, -1},   { 0, 0 },   { 0, 1 } }
        };

        for (int i = 0; i < 4 ; i++) {
            for (int j = 0; j < 2; ++j)
                coords[i][j] = coordsTable[forma][i][j];
        }
        formaPieza = forma;
}
int Pieza::minX() const
{
    int min = coords[0][0];
    for (int i = 1; i < 4; ++i)
        min = qMin(min, coords[i][0]);
    return min;
}

int Pieza::maxX() const

{
    int max = coords[0][0];
    for (int i = 1; i < 4; ++i)
        max = qMax(max, coords[i][0]);
    return max;
}

int Pieza::minY() const
{
    int min = coords[0][1];
    for (int i = 1; i < 4; ++i)
        min = qMin(min, coords[i][1]);
    return min;
}

int Pieza::maxY() const

{
    int max = coords[0][1];
    for (int i = 1; i < 4; ++i)
        max = qMax(max, coords[i][1]);
    return max;
}

Pieza Pieza::rotateLeft() const
{
    if (formaPieza == formaO)
        return *this;

    Pieza result;
    result.formaPieza = formaPieza;
    for (int i = 0; i < 4; ++i) {
        result.setX(i, y(i));
        //qDebug()<<y(i)<<"\n";
        result.setY(i, -x(i));
       // qDebug()<<-x(i)<<"\n";
    }

    return result;
}

Pieza Pieza::rotateRight() const
{
    if (formaPieza == formaO)
        return *this;

    Pieza result;
    result.formaPieza = formaPieza;
    for (int i = 0; i < 4; ++i) {
        result.setX(i, -y(i));
        result.setY(i, x(i));
    }

    return result;
}
