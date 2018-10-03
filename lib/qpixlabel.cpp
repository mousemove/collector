#include "qpixlabel.h"

QPixLabel::QPixLabel(QWidget *parent) : QLabel(parent)
{
}

void QPixLabel::set_pix(QString str)
{
 pixMap = QPixmap(str);
 pixSet = 1;
}

void QPixLabel::set_pix(QPixmap str)
{
    pixMap = str;
    pixSet = 1;
}

void QPixLabel::off_pix()
{
    pixSet = 0;
}


void QPixLabel::paintEvent(QPaintEvent *event) {
    if (pixSet){
QPixmap pix = pixMap;
    if(pix.isNull() == false) {
        QRect rectFound = this->rect();

        if(rectFound.width() > rectFound.height())
            pix = pix.scaledToHeight(rectFound.height());
        else if(rectFound.height() > rectFound.width())
            pix = pix.scaledToWidth(rectFound.width());

        rectFound = pix.rect();
        rectFound.moveCenter(rect().center());

        const QBrush brush(QColor(135,169,229));

        const QPen pen(brush, 8);

        QPainter painter(this);
        painter.setPen(pen);
       // painter.setBrush(brush);
        painter.drawPixmap(rectFound, pix);
                rectFound.setLeft(rectFound.left()+4);
                         rectFound.setRight(rectFound.right()-3);
              rectFound.setTop(rectFound.top()+4);
        rectFound.setBottom(rectFound.bottom()-3);
        //painter.drawRoundRect(rectFound,0,0);
        painter.drawLine(rectFound.topLeft(),rectFound.topRight());
        painter.drawLine(rectFound.topRight(),rectFound.bottomRight());
        painter.drawLine(rectFound.bottomRight(),rectFound.bottomLeft());
        painter.drawLine(rectFound.bottomLeft(),rectFound.topLeft());

    }

    event->accept();
    }
    else
    {
        QLabel::paintEvent(event);
    }
}
