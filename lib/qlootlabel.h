#ifndef QLOOTLABEL_H
#define QLOOTLABEL_H

#include <QObject>
#include <QtWidgets>
#include <QDebug>
#include <lib/structs.h>
#include "lib/qpixlabel.h"
class qlootlabel : public QPixLabel
{
    Q_OBJECT
private:
  lootItem  item;
public:
    qlootlabel(lootItem  item,QWidget * parent  = nullptr);
protected:
    void mouseReleaseEvent(QMouseEvent * me);
    void mouseDoubleClickEvent(QMouseEvent * me);

signals:
    void signal_open_full(lootItem);

};

#endif // QLOOTLABEL_H
