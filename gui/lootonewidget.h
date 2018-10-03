#ifndef LOOTONEWIDGET_H
#define LOOTONEWIDGET_H

#include <QWidget>
#include <QtWidgets>
namespace Ui {
class lootonewidget;
}

class lootonewidget : public QWidget
{
    Q_OBJECT

public:
    explicit lootonewidget(QWidget *parent = nullptr);
    ~lootonewidget();
    void set_data(QString name,QString pix, QString about,int quality);

private:
    QPixmap pixmap;
    Ui::lootonewidget *ui;
    void set_style();
protected:
    void mouseReleaseEvent(QMouseEvent * me);
signals:
    void signal_go_to_collection();
};

#endif // LOOTONEWIDGET_H
