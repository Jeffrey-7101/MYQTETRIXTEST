#ifndef QTETRIXBOARD_H
#define QTETRIXBOARD_H

#include <QFrame>
#include <QObject>
#include <QLabel>
#include <QPointer>
#include <QBasicTimer>
#include "Pieza.h"
class QTetrixBoard : public QFrame
{
    Q_OBJECT
public:
    QTetrixBoard(QWidget *parent = nullptr, int _dificult=1);

    void setNextLabel(QLabel *label);
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

    void setDificultBoard(int d){this->dificultBoard=d;};
    void tryDifficult();
private:
    enum{BoardWidth =10, BoardHeight =22};

   QBasicTimer timer;
   QPointer<QLabel> nextPieceLabel;
   bool isStarted;
   bool isPaused;
   bool isWaitingAfterLine;
   Pieza curPiece;
   Pieza nextPiece;
   int curX;
   int curY;
   int numLinesRemoved;
   int numPiecesDropped;
   int score;
   int level;
   int dificultBoard;


   Forma board[BoardWidth * BoardHeight];

   Forma &format(int x, int y){return board[(y* BoardWidth)+x];}
   int timeOut(){
       return 1000/(1+level);
   }
   int squareWidht(){//ancho de la ventana
       return contentsRect().width()/BoardWidth;
   }
   int squareHeight(){// altura de la ventana
       return contentsRect().height()/BoardHeight;
   }
   void clear();        //vacia la ventana
   void dropDown();     //minimizar
   void oneLineDown();
   void pieceDropped(int dropHeight);
   void removeFullLines();
   void newPiece();
   void newBastardPiece();
   void showNextPiece();
   bool tryMove(const Pieza &newPiece, int newX, int newY);         //verifica si la pieza se puede mover
   void drawSquare(QPainter &painter, int x, int y, Forma forma);




public slots:
    void start();
    void pause();
    void difficult(int d);
signals:
    void scoreChanged(int score);
    void levelChanged(int level);
    void linesRemovedChanged(int numLines);
    void gameOver();

protected:
    void paintEvent(QPaintEvent *event)override;
    void keyPressEvent(QKeyEvent *event)override;
    void timerEvent(QTimerEvent *event)override;



};

#endif // QTETRIXBOARD_H
