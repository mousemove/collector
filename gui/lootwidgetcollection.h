#ifndef LOOTWIDGETCOLLECTION_H
#define LOOTWIDGETCOLLECTION_H

#include <QWidget>
#include <QtWidgets>
#include <QDebug>
#include <lib/structs.h>
#include "lib/qlootlabel.h"
namespace Ui {
class lootwidgetcollection;
}

class lootwidgetcollection : public QWidget
{
    Q_OBJECT

public:
    explicit lootwidgetcollection(QWidget *parent = nullptr);
    ~lootwidgetcollection();
    void refresh_collection(QVector<lootItem> * prizes);

protected:
    void resizeEvent (QResizeEvent * q);
private:

    Ui::lootwidgetcollection *ui;
    QGridLayout * box;
    QFrame * frame;
    QVector<QLabel *> labels;
    QString styleSheet;
    void set_style();
public slots:
    void    slot_open_full(lootItem item);
signals:
    void signal_open_full(lootItem item);

};

#endif // LOOTWIDGETCOLLECTION_H
