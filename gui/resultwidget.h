#ifndef RESULTWIDGET_H
#define RESULTWIDGET_H

#include <QWidget>
#include <QtWidgets>
namespace Ui {
class resultwidget;
}

class resultwidget : public QWidget
{
    Q_OBJECT
private:
    //Данные для активности - Результат.
    bool QResultC;
    bool finishC;
    int moneyC;
    void set_style();
    QPixmap winner,lose,draw,check;
public:
    explicit resultwidget(QWidget *parent = nullptr);
    ~resultwidget();
public slots:
    void slow_show_result(bool QResult,bool finish,int money);
    void slot_timer();
signals:
    void signal_show_result();
    void signal_end_game(int);
    void signal_next_question();
private:
    Ui::resultwidget *ui;
    QTimer timer;
};

#endif // RESULTWIDGET_H
