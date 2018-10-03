#ifndef HALLWIDGET_H
#define HALLWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QtWidgets>
namespace Ui {
class hallwidget;
}

class hallwidget : public QWidget
{
    Q_OBJECT
private:
    int correctNumber;
    void set_style();

public:
    explicit hallwidget(QWidget *parent = nullptr);
    ~hallwidget();

    void setCorrectNumber(int value);
 void mousePressEvent(QMouseEvent * e);
signals:
    void   signal_exit_hall();
private:
    Ui::hallwidget *ui;
};

#endif // HALLWIDGET_H
