#include "resultwidget.h"
#include "ui_resultwidget.h"



resultwidget::resultwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::resultwidget)
{
    ui->setupUi(this);
    timer.setInterval(100);
    connect(&timer,SIGNAL(timeout()),this,SLOT(slot_timer()));
    set_style();

    lose = QPixmap(":/images/bb.png").scaledToHeight(QApplication::desktop()->screenGeometry().height()/4);
    draw = QPixmap(":/images/handshake-003.png").scaledToHeight(QApplication::desktop()->screenGeometry().height()/4);
    winner = QPixmap(":/images/medal.png").scaledToHeight(QApplication::desktop()->screenGeometry().height()/4);
    check = QPixmap(":/images/Check.png").scaledToHeight(QApplication::desktop()->screenGeometry().height()/4);

}

resultwidget::~resultwidget()
{
    delete ui;
}

void resultwidget::slow_show_result(bool QResult, bool finish, int money)
{
    QString result;

    QResultC = QResult;
    finishC = finish;
    moneyC = money;
    if (QResultC == false && finishC == true)
    {

        result = result + "Вы забрали денежки.<br>Конец! Ваш выигрыш составил "+ QString().setNum(money) + " $" ;
        ui->label_2->setPixmap(draw);
    }
    else
    {
        result = result + "Вы " + (QResult ? "ответили верно." : "проиграли.") + "<br> " + (finish ? "Конец!!!!<br> " : "") + " Ваш выигрыш  - "+ QString().setNum(money) + " $" ;
     ui->label_2->setPixmap(QResult ? (finish ?  winner : check) : lose );
    }

    ui->label->setText(result  );
    //qDebug() << result;
    emit signal_show_result();
    timer.start();

}

void resultwidget::slot_timer()
{
    static int i = 0;
    i++;

    if (QResultC == false && finishC == true)
    {

        if (i > 30)  { emit signal_end_game(moneyC);
            i = 0;
            timer.stop();

        }


    }
    else
    {

        if (finishC || !QResultC)
        { if (i > 30)  { emit signal_end_game(moneyC);
                i = 0;
                timer.stop();

            }
        }

        else  { if (i > 15) { emit signal_next_question();
                i = 0;
                timer.stop();}
        }

    }

}

void resultwidget::set_style()
{
    QFile file(":/qss/qss/style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setMinimumHeight(QApplication::desktop()->screenGeometry().height()/2);
}
