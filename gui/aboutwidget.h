#ifndef ABOUTWIDGET_H
#define ABOUTWIDGET_H

#include <QWidget>
#include <QFile>
namespace Ui {
class aboutWidget;
}

class aboutWidget : public QWidget
{
    Q_OBJECT

public:
    explicit aboutWidget(QWidget *parent = nullptr);
    ~aboutWidget();

private:
    Ui::aboutWidget *ui;
    void set_style();
protected:
    void mouseReleaseEvent(QMouseEvent * me);
signals:
    void signal_go_back();
};

#endif // ABOUTWIDGET_H
