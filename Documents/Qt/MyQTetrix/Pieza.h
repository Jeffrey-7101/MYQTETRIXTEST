#ifndef PIEZA_H
#define PIEZA_H

#include <QObject>

enum Forma{sinForma, formaZ,formaS, formaI, formaT, formaO, formaL, reflejo};


class Pieza{

private:

    //cambia la forma
    void setX(int index, int x){coords[index][0]=x;}
    void setY(int index, int y){coords[index][1]=y;}
    //forma de la pieza
    Forma formaPieza;

    //espacio general para cada pieza
    int coords[4][2];

public:
    Pieza(){
        setShape(sinForma);
    }
    void setRandomShape();
    void setBastardShape();

    void setShape(Forma forma);



    Forma shape() const{return formaPieza; }
    int x(int index) const{return coords[index][0];}//getX
    int y(int index) const{return coords[index][1];}//getY

    int minX() const;
    int maxX() const;
    int minY() const;
    int maxY() const;

    Pieza rotateLeft() const;
    Pieza rotateRight() const;

public slots:

};

#endif // PIEZA_H
