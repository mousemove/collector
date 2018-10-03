#include "qlootlabel.h"

qlootlabel::qlootlabel(lootItem item,QWidget * parent) : QPixLabel (parent), item(item)
{

}

void qlootlabel::mouseReleaseEvent(QMouseEvent *me)
{


   emit signal_open_full(item);

}

void qlootlabel::mouseDoubleClickEvent(QMouseEvent *me)
{
    //emit signal_open_full(name,pix, about,quality);
}

