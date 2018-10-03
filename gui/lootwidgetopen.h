#ifndef LOOTWIDGETOPEN_H
#define LOOTWIDGETOPEN_H

#include <QWidget>
#include <QtWidgets>
#include <QDebug>
#include "lib/structs.h"
namespace Ui {
class lootwidgetopen;
}

class lootwidgetopen : public QWidget
{
    Q_OBJECT

public:
    explicit lootwidgetopen(QWidget *parent = nullptr);
    ~lootwidgetopen();
public slots:
    void slot_open_case( lootItem li);
protected:
    void mouseReleaseEvent(QMouseEvent * me);

private:
    Ui::lootwidgetopen *ui;
    void set_style();
    QPixmap pix;

signals:
    void signal_back_to_collection();
};

#endif // LOOTWIDGETOPEN_H
