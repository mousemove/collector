#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtWidgets>
#include <QDebug>
#include <QtSql>
#include "lib/structs.h"
#include "QTime"


class database : public QObject
{
    Q_OBJECT
private:
    bool createConnection();
    void create_tables(void);
    void fill_questions();
    void fill_loot();
    public:
    explicit database(QObject *parent = nullptr);


signals:
    void signal_send_question(int number,QString question,QString pix,QString one, QString two, QString three, QString four, int correct);
    void signal_loot_refresh(); // для маршрутизатора и для лутвиджета
    void signal_send_loot_box(lootItem);
    void signal_send_stats(int);
public slots:
    void slot_get_query_for_question(int level, QVector<int> & answered);
    void slot_refresh_loot_vector(QVector<lootItem> * lootVector);
    void slot_query_open_lootbox();

};

#endif // DATABASE_H
