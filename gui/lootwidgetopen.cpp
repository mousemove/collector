#include "lootwidgetopen.h"
#include "ui_lootwidgetopen.h"

lootwidgetopen::lootwidgetopen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lootwidgetopen)
{

    ui->setupUi(this);
       set_style();
}

lootwidgetopen::~lootwidgetopen()
{
    delete ui;
}

void lootwidgetopen::slot_open_case(lootItem  li)
{
    pix.load(":/l/images/loot/"+li.pix.trimmed());
    ui->label_3->setPixmap(pix.scaledToHeight(QApplication::desktop()->screenGeometry().height()/3 - 30));
    ui->label_2->setText(li.name);
    ui->label_6->setText(li.quality == 1 ? "Качество: Обычное." :  li.quality == 2 ? "Качество: РЕДКОЕ " : "Качество: ЛЕГЕНДАРНОЕ(!!!)  ");

    ui->label_4->setText(li.description);
    ui->label_5->setText(li.count == 0? "ПЕРВОЕ ОТКРЫТИЕ!!!!" : "Вам уже выпадала эта вещь, открытий: "+QString().setNum(li.count)+ "");
}
void lootwidgetopen::mouseReleaseEvent(QMouseEvent * me)
{
    emit signal_back_to_collection();
}

void lootwidgetopen::set_style()
{
  ui->label->setAlignment(Qt::AlignCenter);
    ui->label_2->setAlignment(Qt::AlignCenter);
  ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label_4->setAlignment(Qt::AlignCenter);
        ui->label_5->setAlignment(Qt::AlignCenter);
          ui->label_6->setAlignment(Qt::AlignCenter);
             ui->label_3->setMinimumHeight(QApplication::desktop()->screenGeometry().height()/2);
             ui->label_3->setMaximumHeight(QApplication::desktop()->screenGeometry().height()/2);
             ui->label_3->setMinimumWidth(QApplication::desktop()->screenGeometry().width()-40);
             ui->label_3->setMaximumWidth(QApplication::desktop()->screenGeometry().width()-40);

}
