#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include "QTime"
#include "lib/structs.h"
namespace Ui {
class gamewidget;
}

class gamewidget : public QWidget
{
    Q_OBJECT
private:
    QVector<QPushButton *> questionbutton;
    QPushButton * correctButton = nullptr;
    QPushButton * selectedButton = nullptr;
    int corButtNumber = 0; //Используется для подсказок
    QString styleSheetGreenButton;
    QString styleSheetNoSelectButton;
    QString styleSheetOrangeButton;
    //Таймер пост-выборной анимации
    QTimer timer;
    //Данные для GUI
    int qMoney;//денег за вопрос
    int qNumber;//номер вопроса
public:
    explicit gamewidget(QWidget *parent = nullptr);
    ~gamewidget();
    void refresh_data(   );
    void set_style();
private:
    Ui::gamewidget *ui;
signals:
    void signal_ready(); //сигнал для роутера, мол загрузили данные из БД переходим к отображению
    void signal_result(bool);
    void signal_activate_hint( gameHints );
    void signal_call_hint(int num);
    void signal_hall_hint(int num);
    void signal_took();
public slots:
    void slot_from_logic(QString question,QString pix,QString * list, int correct,bool * hints,int money,int number);
    void slot_button_clicked();
    void slot_for_timer();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
};

#endif // GAMEWIDGET_H
