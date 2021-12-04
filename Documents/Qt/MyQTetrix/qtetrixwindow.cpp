#include "qtetrixwindow.h"
#include "dificultwindow.h"
#include <QCoreApplication>
#include <QGridLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>


QTetrixWindow::QTetrixWindow(QWidget *parent)
    : QWidget(parent), board(new QTetrixBoard)
{

        nextPieceLabel = new QLabel;                                    //inicializa labels
        nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);    //estilo
        nextPieceLabel->setAlignment(Qt::AlignCenter);                  //alineacion
        board->setNextLabel(nextPieceLabel);                       //asigna a la board

        scoreLcd = new QLCDNumber(5);                   //inicializa contadores
        scoreLcd->setSegmentStyle(QLCDNumber::Outline);

        levelLcd = new QLCDNumber(2);//valor por defecto
        levelLcd->setSegmentStyle(QLCDNumber::Outline);
        linesLcd = new QLCDNumber(5);//valor por defecto
        linesLcd->setSegmentStyle(QLCDNumber::Outline);
       //dificultLcd = new QLCDNumber(1);//valor por defecto
       // qDebug()<<this->dificultad;
       // dificultLcd->setSegmentStyle(QLCDNumber::Outline);

        startButton = new QPushButton(tr("&Start"));    //inicializa botones
        startButton->setFocusPolicy(Qt::NoFocus);
        quitButton = new QPushButton(tr("&Quit"));
        quitButton->setFocusPolicy(Qt::NoFocus);
        pauseButton = new QPushButton(tr("&Pause"));
        pauseButton->setFocusPolicy(Qt::NoFocus);



    // eventos, presionar boton invoca a una funcion
    //  connect(objeto1,eventoObjeto1, Objeto2,slotObjeto2)
        connect(startButton, &QPushButton::clicked, board, &QTetrixBoard::start);
        connect(quitButton , &QPushButton::clicked, qApp, &QCoreApplication::quit);
        connect(pauseButton, &QPushButton::clicked, board, &QTetrixBoard::pause);



        connect(board, &QTetrixBoard::scoreChanged,scoreLcd, qOverload<int>(&QLCDNumber::display));
        connect(board, &QTetrixBoard::levelChanged,levelLcd, qOverload<int>(&QLCDNumber::display));
        connect(board, &QTetrixBoard::linesRemovedChanged, linesLcd, qOverload<int>(&QLCDNumber::display));

    //! [5]

    //! [6]
    // orden del layout
    /*
     * 00.   01  02.
     * 10.   11  12.
     * 20.   21  22.
     * 30.   31  32.
     * 40.   41  42.
     * 50    51  52.
     */
        QGridLayout *layout = new QGridLayout;
        layout->addWidget(createLabel(tr("NEXT")), 0, 0);
        layout->addWidget(nextPieceLabel, 1, 0);
        layout->addWidget(createLabel(tr("LEVEL")), 2, 0);
        layout->addWidget(levelLcd, 3, 0);
        layout->addWidget(startButton, 4, 0);
        layout->addWidget(createLabel(tr("DIFICULTAD")),5,0);
        if(this->dificultad==1)
            layout->addWidget(createLabel(tr("FÁCIL")),6,0);
        else
            layout->addWidget(createLabel(tr("OTRO")),6,0);

        layout->addWidget(board, 0, 1, 6, 1);
        layout->addWidget(createLabel(tr("SCORE")), 0, 2);
        layout->addWidget(scoreLcd, 1, 2);
        layout->addWidget(createLabel(tr("LINES REMOVED")), 2, 2);
        layout->addWidget(linesLcd, 3, 2);
        layout->addWidget(quitButton, 4, 2);
        layout->addWidget(pauseButton, 5, 2);
        setLayout(layout);

        setWindowTitle(tr("Tetrix"));
        resize(550, 370);
    }
    //! [6]

    //! [7]
    QLabel *QTetrixWindow::createLabel(const QString &text) // le da formato a label
    {
        QLabel *label = new QLabel(text);
        label->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
        return label;
    }
   void QTetrixWindow::easy(int d){
        qDebug()<<"modo facil";
        emit dificultSignal(1);

        this->show();
    }
    void QTetrixWindow::normal(int d){
        qDebug()<<"modo normal";
        emit dificultSignal(2);
        this->show();
    }

    void QTetrixWindow::bastard(int d){
        qDebug()<<"modo bastard";
        emit dificultSignal(3);
        this->show();

    }
    //SLOTS
    /*void QTetrixWindow::dificultSlot(int d){
        this->dificultad=d;

    }*/
