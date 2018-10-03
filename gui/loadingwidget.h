#ifndef LOADINGWIDGET_H
#define LOADINGWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QDebug>
#include <QGraphicsOpacityEffect>
class loadingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit loadingWidget(QWidget *parent = nullptr);
    ~loadingWidget();
private:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QTimer * timer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPixmap  loading_logo;
    //QGraphicsOpacityEffect * op;// Графический эффект для плавного перехода прозрачности
    void setupUI();

signals:
    void animation_end();
public slots:
private slots:
       void timer_function();
};

#endif // LOADINGWIDGET_H
