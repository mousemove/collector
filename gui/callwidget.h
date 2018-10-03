#ifndef CALLWIDGET_H
#define CALLWIDGET_H

#include <QWidget>
#include <QtWidgets>
namespace Ui {
class callwidget;
}
    const int count_characters = 2;
class callwidget : public QWidget
{
    Q_OBJECT
private:
    int correctNumber;

    /* Эти данные можно в дальнейшем вынести в БД. Но есть ли в этом дополнительная надобность? */
    QString faces[count_characters] = {":/сhararters/images/chars/1.jpg",":/сhararters/images/chars/2.jpg"} ;
    QString names[count_characters] = {"Вован","Димон"} ;
    QString quotes[count_characters] = {"Своих не бросаем. Думаю что ответ - ANSWER","Ответ ANSWER. Держитесь там Хорошего вам настроения."} ;
   int brainlevel[count_characters] = {95,40} ;\
   void set_style();
QPixmap pix;
public:
    explicit callwidget(QWidget *parent = nullptr);
    ~callwidget();
    void setCorrectNumber(int value);

public slots:
    void mousePressEvent(QMouseEvent * e);
signals :
        void   signal_exit_call();
private:
    Ui::callwidget *ui;
};

#endif // CALLWIDGET_H
