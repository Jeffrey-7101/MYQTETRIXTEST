#include "qtetrixwindow.h"
#include "dificultwindow.h"
#include <QCoreApplication>
#include <QGridLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
#include <QMessageBox>
#include <QPalette>

QTetrixWindow::QTetrixWindow(QWidget *parent)
    : QWidget(parent),board(new QTetrixBoard)
{
        //this->aux=x;

        board->setStyleSheet("background-color:black;");
        this->setStyleSheet("background-color:gray ;");
        nextPieceLabel = new QLabel;                                    //inicializa labels
        nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);    //estilo
        nextPieceLabel->setAlignment(Qt::AlignCenter);                //alineacion
        nextPieceLabel->setStyleSheet("background-color:black;");
        board->setNextLabel(nextPieceLabel);                       //asigna a la board

        scoreLcd = new QLCDNumber(5);                   //inicializa contadores
        scoreLcd->setSegmentStyle(QLCDNumber::Outline);
        scoreLcd->setStyleSheet("background-color:black;");

        levelLcd = new QLCDNumber(2);//valor por defecto
        levelLcd->setSegmentStyle(QLCDNumber::Outline);
        levelLcd->setStyleSheet("background-color:black;");

        linesLcd = new QLCDNumber(5);//valor por defecto
        linesLcd->setSegmentStyle(QLCDNumber::Outline);
        linesLcd->setStyleSheet("background-color:black;");



        startButton = new QPushButton(tr("&Start"));    //inicializa botones
        startButton->setFocusPolicy(Qt::NoFocus);
        //quitButton = new QPushButton(tr("&Quit"));
        //quitButton->setFocusPolicy(Qt::NoFocus);
        pauseButton = new QPushButton(tr("&Pause"));
        pauseButton->setFocusPolicy(Qt::NoFocus);



    // eventos, presionar boton invoca a una funcion
    //  connect(objeto1,eventoObjeto1, Objeto2,slotObjeto2)
        connect(startButton, &QPushButton::clicked, board, &QTetrixBoard::start);
        //connect(quitButton , &QPushButton::clicked, qApp, &QCoreApplication::quit);
        connect(pauseButton, &QPushButton::clicked, board, &QTetrixBoard::pause);



        connect(board, &QTetrixBoard::scoreChanged,scoreLcd, qOverload<int>(&QLCDNumber::display));
        connect(board, &QTetrixBoard::levelChanged,levelLcd, qOverload<int>(&QLCDNumber::display));
        connect(board, &QTetrixBoard::linesRemovedChanged, linesLcd, qOverload<int>(&QLCDNumber::display));



        board->tryDifficult();

    //! [5]

    //! [6]
    // orden del layout
    /*
     * 00.   01  02.score       NEXT
     * 10.   11  12.scoreLCD    NEXTLCD
     * 20.   21  22.Lines       SCORE
     * 30.   31  32.linesLCD    SCORELCD
     * 40.   41  42.Pausa botón LINES
     * 50    51  52.            LINESLCD
     * 60   61  62
     */
        QGridLayout *layout = new QGridLayout;
        layout->addWidget(createLabel(tr("NEXT")), 0, 2);
        layout->addWidget(nextPieceLabel, 1, 2);
        //layout->addWidget(createLabel(tr("LEVEL")), 2, 0);
        //layout->addWidget(levelLcd, 3, 0);
        //layout->addWidget(startButton, 4, 0);

        //----------------------------------------------------------------

        //layout->addWidget(createLabel(tr("DIFICULTAD: FÁCIL")),5,0)
        /*qDebug()<<"Layout:"<<this->dificultadWindow;
        if(this->dificultadWindow==1)
            layout->addWidget(createLabel(tr("DIFICULTAD: FÁCIL")),5,0);
        else if(this->dificultadWindow==2){
            layout->addWidget(createLabel(tr("DIFICULTAD: MEDIO")),5,0);
        }
        else if(this->dificultadWindow==3){
            layout->addWidget(createLabel(tr("DIFICULTAD: BASTARD")),5,0);
        }*/

        //------------------------------------------------------------------


       // qDebug()<<this->dificultadWindow;
        //layout->addWidget(dificultLcd,6,0);
        layout->addWidget(board, 0, 1, 6, 1);
        layout->addWidget(createLabel(tr("SCORE")), 2, 2);
        layout->addWidget(scoreLcd, 3, 2);
        layout->addWidget(createLabel(tr("LINES REMOVED")), 4, 2);
        layout->addWidget(linesLcd, 5, 2);
        //layout->addWidget(quitButton, 4, 2);

        if(this->dificultadWindow!=3)
            layout->addWidget(pauseButton, 6, 2);
        setLayout(layout);

        setWindowTitle(tr("Tetrix"));
        resize(400, 600);
    }

   QLabel *QTetrixWindow::createLabel(const QString &text) // le da formato a label
    {
        QLabel *label = new QLabel(text);
        label->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
        return label;
    }

   //SLOTS


   void QTetrixWindow::easy(){
        qDebug()<<"modo facil";
        this->dificultadWindow=1;
        emit dificultSignal(1);
        this->show();
        board->start();

    }
    void QTetrixWindow::normal(){
        qDebug()<<"modo normal";
        this->dificultadWindow=2;
        emit dificultSignal(2);
        this->show();
        board->start();
    }

    void QTetrixWindow::bastard(){
        qDebug()<<"modo bastard";
        this->dificultadWindow=3;
        emit dificultSignal(3);
        this->show();
        board->start();
    }

    void QTetrixWindow::gameOver(){
        qDebug()<<"GAME OVER";

        QMessageBox::information(this,tr("My QTetrix"),tr("GAME OVER"));
    }

