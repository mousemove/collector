#ifndef WIDGETSTATISTICS_H
#define WIDGETSTATISTICS_H

#include <QWidget>
#include <QFile>
namespace Ui {
class widgetstatistics;
}

class widgetstatistics : public QWidget
{
    Q_OBJECT

public:
    explicit widgetstatistics(QWidget *parent = nullptr);
    ~widgetstatistics();
    void set_stat(int money,int open,int common,int rare,int legendary);
protected:
    void mouseReleaseEvent(QMouseEvent * me);
signals:
    void signal_go_back();
private:
    Ui::widgetstatistics *ui;
    void set_style();
};

#endif // WIDGETSTATISTICS_H
