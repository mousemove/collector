#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "lib/withoutfilterstyle.h"
mainwidget::mainwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainwidget)
{
    ui->setupUi(this);

    /* доНастойка ГУЯ после инициализации */
    pix = QPixmap(":/images/main_logo.png").scaledToWidth(QApplication::desktop()->screenGeometry().width()-30);
    ui->label->setPixmap(pix);
    // Создаём палитру для тёмной темы оформления
    set_style();

}
mainwidget::~mainwidget()
{
    delete ui;
}

void mainwidget::on_pushButton_clicked()
{
    emit signal_new_game();
}

void mainwidget::on_pushButton_2_clicked()
{
    emit signal_go_to_loot();
}

void mainwidget::on_pushButton_3_clicked()
{
    emit signal_go_to_stat();
}

void mainwidget::on_pushButton_4_clicked()
{
    emit signal_go_to_about();
}

void mainwidget::on_pushButton_5_clicked()
{
    QApplication::quit();
}

void mainwidget::set_style()
{
    QFile file(":/qss/qss/style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
    ui->pushButton->setFocusPolicy(Qt::NoFocus);

    ui->pushButton_2->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_3->setFocusPolicy(Qt::NoFocus);

    ui->pushButton_4->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_5->setFocusPolicy(Qt::NoFocus);


QFile filebigbutton(":/qss/qss/sbbigbutton.qss");
filebigbutton.open(QFile::ReadOnly);
QString styleSheetfilebigbutton = QLatin1String(filebigbutton.readAll());
ui->pushButton_4->setStyleSheet(styleSheetfilebigbutton);
ui->pushButton_5->setStyleSheet(styleSheetfilebigbutton);
ui->pushButton_4->setMinimumHeight(QApplication::desktop()->screenGeometry().height()/8);
ui->pushButton_5->setMinimumHeight(QApplication::desktop()->screenGeometry().height()/8);
ui->pushButton_4->setMinimumWidth(QApplication::desktop()->screenGeometry().width()/4);
ui->pushButton_5->setMinimumWidth(QApplication::desktop()->screenGeometry().width()/4);
}
