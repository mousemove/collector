#include "phonevectqscrollarea.h"

phoneVectQScrollArea::phoneVectQScrollArea(QWidget * parent) : QScrollArea(parent)
{

}



void phoneVectQScrollArea::mousePressEvent(QMouseEvent *me)
{

    oldPos = me->pos();
}

void phoneVectQScrollArea::mouseReleaseEvent(QMouseEvent *me)
{
    qDebug() << "MR";
    iniMove  = 0;
}

void phoneVectQScrollArea::mouseMoveEvent(QMouseEvent *me)
{
    qDebug() << "MM";
    iniMove  = 1;
    if (   oldPos.y() < me->pos().y() ) {
        verticalScrollBar()->setValue(verticalScrollBar()->value()+ oldPos.y() - me->pos().y());
    }
    if (   oldPos.y() > me->pos().y() ) {
        verticalScrollBar()->setValue(verticalScrollBar()->value()+ oldPos.y() - me->pos().y());
    }
    oldPos = me->pos();
}

int phoneVectQScrollArea::getIniMove() const
{
    return iniMove;
}

void phoneVectQScrollArea::setIniMove(int value)
{
    iniMove = value;
}
