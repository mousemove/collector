


#ifndef QPIXLABEL_H
#define QPIXLABEL_H

#include <QObject>
#include <QtWidgets>
class QPixLabel : public QLabel
{
    Q_OBJECT
private:
    int pixSet = 0;
    QPixmap pixMap;
public:
    explicit QPixLabel(QWidget *parent = nullptr);
    void set_pix(QString str);
    void set_pix(QPixmap str);
    void off_pix();
signals:

public slots:
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // QPIXLABEL_H
