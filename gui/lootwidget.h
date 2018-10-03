#ifndef LOOTWIDGET_H
#define LOOTWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include "lib/structs.h"
#include "lootwidgetcollection.h"
#include "lootwidgetopen.h"
#include "lootonewidget.h"
/* Класс имеет два суб виджета, которые не контактируют с маршрутизатором, а контактируют только с этим классом.  */
namespace Ui {
class lootwidget;
}

static int box_price = 2000;
class lootwidget : public QWidget
{
    Q_OBJECT
private:
    QVector<lootItem> prizes;
    lootwidgetcollection * collection;
    lootwidgetopen * opencase;
    lootonewidget * lootView;
    int money;
    void set_style();
public:
    explicit lootwidget(QWidget *parent = nullptr);
    void refresh_items(int money);
    ~lootwidget();
signals:
    void signal_refresh_loot(QVector<lootItem> * lootVector);
    void signal_query_loot_box();
    void signal_open_loot_box(lootItem li);
    void signal_refresh_money(int money);
    void signal_go_back();
public slots:
    void slot_loot_refresh_from_db();
    void slot_read_opened_lootboox(lootItem li);
    void slot_back_from_opencase();
    void slot_open_full(lootItem li);
    void slot_back_from_view_loot();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::lootwidget *ui;
};

#endif // LOOTWIDGET_H
