#ifndef WITHOUTFILTERSTYLE_H
#define WITHOUTFILTERSTYLE_H

#include <QtWidgets>


class withoutFilterStyle : public QProxyStyle
{
public:
    withoutFilterStyle(QStyle *baseStyle = 0) : QProxyStyle(baseStyle)
    {
    }

    void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
                       QPainter *painter, const QWidget *widget) const
    {
        if(element == QStyle::PE_FrameFocusRect)
        {
            return;
        }
        QProxyStyle::drawPrimitive(element,option,painter,widget);
    }

};

#endif // WITHOUTFILTERSTYLE_H
