#include "qtetrixboard.h"

#include <QPainter>
#include <QKeyEvent>
#include <QLabel>

QTetrixBoard::QTetrixBoard(QWidget *parent, int _dificult)

    :QFrame(parent), isStarted(false), isPaused(false),dificultBoard(_dificult)
{
    setFrameStyle(QFrame:: Panel | QFrame::Sunken);
    setFocusPolicy(Qt::StrongFocus);
    clear();

    nextPiece.setRandomShape();
}
void QTetrixBoard:: setNextLabel(QLabel *label){
    nextPieceLabel=label;
}

QSize QTetrixBoard::sizeHint() const{
    return QSize(BoardWidth*15+frameWidth()*5, BoardHeight*15+frameWidth()*5);
}

QSize QTetrixBoard::minimumSizeHint() const{
    return QSize(BoardWidth * 5 + frameWidth() * 2, BoardHeight * 5 + frameWidth() * 2);
}

//SLOTS
void QTetrixBoard::start(){
    if(isPaused)
        return;
    else{
        qDebug()<<this->dificultBoard;
        isStarted = true;
        isWaitingAfterLine = false;
        numLinesRemoved=0;
        numPiecesDropped=0;
        score=0;
        if(this->dificultBoard==3){
            level=5;
        }
        else
            level=1;

        }
        clear();

        emit linesRemovedChanged(numLinesRemoved);
        emit scoreChanged(score);
        emit levelChanged(level);

        newPiece();
        timer.start(timeOut(),this);

}
void QTetrixBoard::pause(){
    if(!isStarted)// si el juego no empezo no hace nada
        return;
    isPaused=!isPaused;
    if(isPaused){
        timer.stop();
    }else{
        timer.start(timeOut(),this);
    }

}

void QTetrixBoard::difficult(int d){
    qDebug()<<"Connect with dificult"<<d;
    this->setDificultBoard(d);

}

void QTetrixBoard::tryDifficult(){
    qDebug()<<"Try difficult: "<<this->dificultBoard;
}


void QTetrixBoard::paintEvent(QPaintEvent *event){ // MOVIMIENTO DE FIGURAS
    QFrame::paintEvent(event);
    QPainter painter(this);
    QRect rect= contentsRect();

    if(isPaused){
        painter.drawText(rect,Qt::AlignCenter, tr("Pause"));
    }

    int boardTop=rect.bottom() - BoardHeight*squareHeight();

    for(int i=0;i<BoardHeight;i++){
        for(int j=0;j<BoardWidth;j++){
            Forma forma= format(j,BoardHeight-i-1);
            if(forma != sinForma)
                drawSquare(painter,rect.left()+j*squareWidht(), boardTop+i*squareHeight(),forma);
        }
    }
    if (curPiece.shape() != sinForma) {
            for (int i = 0; i < 4; ++i) {
                int x = curX + curPiece.x(i);
                int y = curY - curPiece.y(i);
                drawSquare(painter, rect.left() + x * squareWidht(),
                           boardTop + (BoardHeight - y - 1) * squareHeight(),
                           curPiece.shape());
            }
    }
}

void QTetrixBoard::keyPressEvent(QKeyEvent *event)
{
    if (!isStarted || isPaused || curPiece.shape() == sinForma) {
        QFrame::keyPressEvent(event);
        return;
    }

    switch (event->key()) {
    case Qt::Key_Left:
        tryMove(curPiece, curX - 1, curY);
        break;
    case Qt::Key_Right:
        tryMove(curPiece, curX + 1, curY);
        break;
    case Qt::Key_Down:
        tryMove(curPiece.rotateRight(), curX, curY);
        break;
    case Qt::Key_Up:
        tryMove(curPiece.rotateLeft(), curX, curY);
        break;
    case Qt::Key_Space:
        dropDown();
        break;
    case Qt::Key_D:
        oneLineDown();
        break;
    default:
        QFrame::keyPressEvent(event);
    }

}

void QTetrixBoard::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer.timerId()) {
        if (isWaitingAfterLine) {
            isWaitingAfterLine = false;
            newPiece();
            timer.start(timeOut(), this);
        } else {
            oneLineDown();
        }
    } else {
        QFrame::timerEvent(event);

    }

}

void QTetrixBoard::clear()
{
    for (int i = 0; i < BoardHeight * BoardWidth; ++i)
        board[i] = sinForma;
}

void QTetrixBoard::dropDown()
{
    int dropHeight = 0;
    int newY = curY;
    while (newY > 0) {
        if (!tryMove(curPiece, curX, newY - 1))
            break;
        --newY;
        ++dropHeight;
    }
    pieceDropped(dropHeight);

}

void QTetrixBoard::oneLineDown()
{
    if (!tryMove(curPiece, curX, curY - 1))
        pieceDropped(0);
}

void QTetrixBoard::pieceDropped(int dropHeight)
{
    for (int i = 0; i < 4; ++i) {
        int x = curX + curPiece.x(i);
        int y = curY - curPiece.y(i);
        format(x, y) = curPiece.shape();
    }

    ++numPiecesDropped;
    if (numPiecesDropped % 25 == 0) {
        ++level;
        timer.start(timeOut(), this);
        emit levelChanged(level);
    }

    score += dropHeight + 7;
    emit scoreChanged(score);
    removeFullLines();

    if (!isWaitingAfterLine)
        newPiece();

}

void QTetrixBoard::removeFullLines()
{
    int numFullLines = 0;

    for (int i = BoardHeight - 1; i >= 0; --i) {
        bool lineIsFull = true;

        for (int j = 0; j < BoardWidth; ++j) {
            if (format(j, i) == sinForma) {
                lineIsFull = false;
                break;
            }
        }

        if (lineIsFull) {

            ++numFullLines;
            for (int k = i; k < BoardHeight - 1; ++k) {
                for (int j = 0; j < BoardWidth; ++j)
                    format(j, k) = format(j, k + 1);
            }

            for (int j = 0; j < BoardWidth; ++j)
                format(j, BoardHeight - 1) = sinForma;
        }

    }

    if (numFullLines > 0) {
        numLinesRemoved += numFullLines;
        score += 10 * numFullLines;
        emit linesRemovedChanged(numLinesRemoved);
        emit scoreChanged(score);

        timer.start(500, this);
        isWaitingAfterLine = true;
        curPiece.setShape(sinForma);
        update();
    }

}

void QTetrixBoard::newPiece()
{
    curPiece = nextPiece;
    nextPiece.setRandomShape();
    showNextPiece();
    curX = BoardWidth / 2 + 1;
    curY = BoardHeight - 1 + curPiece.minY();

    if (!tryMove(curPiece, curX, curY)) {
        curPiece.setShape(sinForma);
        timer.stop();
        isStarted = false;
        emit gameOver();
    }

}
void QTetrixBoard::newBastardPiece(){
    curPiece= nextPiece;
    nextPiece.setRandomShape();
    curX=BoardWidth/2+1;
    curY=BoardHeight-1+curPiece.minY();

    if (!tryMove(curPiece, curX, curY)) {
        curPiece.setShape(sinForma);
        timer.stop();
        isStarted = false;
        emit gameOver();
    }
}

void QTetrixBoard::showNextPiece()
{
    if (!nextPieceLabel)
        return;
    if(this->dificultBoard==3)
        return;

    int dx = nextPiece.maxX() - nextPiece.minX() + 1;
    int dy = nextPiece.maxY() - nextPiece.minY() + 1;

    QPixmap pixmap(dx * squareWidht(), dy * squareHeight());
    QPainter painter(&pixmap);
    painter.fillRect(pixmap.rect(), nextPieceLabel->palette().window());

    for (int i = 0; i < 4; ++i) {
        int x = nextPiece.x(i) - nextPiece.minX();
        int y = nextPiece.y(i) - nextPiece.minY();
        drawSquare(painter, x * squareWidht(), y * squareHeight(),
                   nextPiece.shape());
    }
    nextPieceLabel->setPixmap(pixmap);

}

bool QTetrixBoard::tryMove(const Pieza &newPiece, int newX, int newY)
{
    for (int i = 0; i < 4; ++i) {
        int x = newX + newPiece.x(i);
        int y = newY - newPiece.y(i);
        if (x < 0 || x >= BoardWidth || y < 0 || y >= BoardHeight)
            return false;
        if (format(x, y) != sinForma)
            return false;
    }

    curPiece = newPiece;
    curX = newX;
    curY = newY;
    update();
    return true;
}

void QTetrixBoard::drawSquare(QPainter &painter, int x, int y, Forma shape)
{
    static constexpr QRgb colorTable[8] = {
        0x000000, 0xCC6666, 0x66CC66, 0x6666CC,
        0xCCCC66, 0xCC66CC, 0x66CCCC, 0xDAAA00
    };

    QColor color = colorTable[int(shape)];
    painter.fillRect(x + 1, y + 1, squareWidht() - 2, squareHeight() - 2,
                     color);

    painter.setPen(color.lighter());
    painter.drawLine(x, y + squareHeight() - 1, x, y);
    painter.drawLine(x, y, x + squareWidht() - 1, y);

    painter.setPen(color.darker());
    painter.drawLine(x + 1, y + squareHeight() - 1,
                     x + squareWidht() - 1, y + squareHeight() - 1);
    painter.drawLine(x + squareWidht() - 1, y + squareHeight() - 1,
                     x + squareWidht() - 1, y + 1);
}
