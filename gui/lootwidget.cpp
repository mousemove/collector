#include "lootwidget.h"
#include "ui_lootwidget.h"
#include "QTime"


lootwidget::lootwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lootwidget)
{
    ui->setupUi(this);
    collection = new  lootwidgetcollection(this);
    opencase = new lootwidgetopen(this) ;
    lootView = new lootonewidget(this);
    ui->stackedWidget->addWidget(collection);
    ui->stackedWidget->addWidget(opencase);
    ui->stackedWidget->setCurrentWidget(collection);
    ui->stackedWidget->addWidget(lootView);
    connect(this,SIGNAL(signal_open_loot_box(lootItem)),opencase,SLOT(slot_open_case(lootItem)));
    connect(opencase,SIGNAL(signal_back_to_collection()),this,SLOT(slot_back_from_opencase()));
    connect(collection,SIGNAL(signal_open_full(lootItem)),this,SLOT(slot_open_full(lootItem)));
    connect(lootView,SIGNAL(signal_go_to_collection()),this,SLOT(slot_back_from_view_loot()));
    set_style();
}
/* Функция для вызова из роутера передающая баланс*/
void lootwidget::refresh_items(int money)
{
    this->money = money;
    ui->pushButton->setEnabled(money >= box_price);
    emit signal_refresh_loot(&prizes);
}


lootwidget::~lootwidget()
{

    delete ui;
}

void lootwidget::slot_loot_refresh_from_db()
{
    collection->refresh_collection(&prizes);
    ui->stackedWidget->setCurrentWidget(collection);
    ui->label->setText("Ваш баланс:" + QString().setNum(money) + "$("+QString().setNum(money/box_price)+")");

}

void lootwidget::slot_read_opened_lootboox(lootItem li)
{
    emit signal_refresh_loot(&prizes);
    emit signal_open_loot_box(li);
    ui->stackedWidget->setCurrentWidget(opencase);
    ui->pushButton->setEnabled(false);
}

void lootwidget::slot_back_from_opencase()
{

    ui->stackedWidget->setCurrentWidget(collection);
    ui->pushButton->setEnabled(money >= box_price);
}

void lootwidget::slot_open_full(lootItem li)
{

    lootView->set_data(li.name,li.pix,li.description,li.quality);
    ui->pushButton->setEnabled(false);
    ui->stackedWidget->setCurrentWidget(lootView);
}

void lootwidget::slot_back_from_view_loot()
{
    ui->stackedWidget->setCurrentWidget(collection);
    ui->pushButton->setEnabled(money >= box_price);
    //Повторение slot_back_from_opencase, но пусть будет - мало ли изменится что-то, архитектурно 2 разных выхода будет
}


void lootwidget::on_pushButton_clicked()
{
    emit signal_refresh_money(box_price);
    emit signal_query_loot_box();


}

void lootwidget::on_pushButton_2_clicked()
{
    emit signal_go_back();
}

void lootwidget::set_style()
{
    QFile file(":/qss/qss/style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
    ui->pushButton->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_2->setFocusPolicy(Qt::NoFocus);

    QFile filebigbutton(":/qss/qss/sbbigbutton.qss");
    filebigbutton.open(QFile::ReadOnly);
    QString styleSheetfilebigbutton = QLatin1String(filebigbutton.readAll());
    ui->pushButton->setStyleSheet(styleSheetfilebigbutton);
        ui->pushButton_2->setStyleSheet(styleSheetfilebigbutton);

}
