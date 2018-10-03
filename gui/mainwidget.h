#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QtWidgets>
namespace Ui {
class mainwidget;
}

class mainwidget : public QWidget
{
    Q_OBJECT
private:
    QPixmap  pix;
public:
    explicit mainwidget(QWidget *parent = nullptr);
    ~mainwidget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::mainwidget *ui;

    void set_style();
signals:
    void    signal_new_game();
    void signal_go_to_loot();
        void signal_go_to_stat();
        void signal_go_to_about();
};

#endif // MAINWIDGET_H
