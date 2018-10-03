#ifndef PHONEVECTQSCROLLAREA_H
#define PHONEVECTQSCROLLAREA_H

#include <QObject>
#include <QtWidgets>
#include <QDebug>
class phoneVectQScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    phoneVectQScrollArea(QWidget * parent  = nullptr);
    int getIniMove() const;
    void setIniMove(int value);

protected:
    void mousePressEvent(QMouseEvent * me);
     void mouseReleaseEvent(QMouseEvent * me);
      void mouseMoveEvent(QMouseEvent * me);
signals:
      void signal_init_move();
      void signal_end_move();
private:
      QPoint oldPos;
      QPoint FinPos;
      int iniMove = 0;


};

#endif // PHONEVECTQSCROLLAREA_H
