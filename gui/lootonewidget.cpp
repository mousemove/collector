#include "lootonewidget.h"
#include "ui_lootonewidget.h"

lootonewidget::lootonewidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lootonewidget)
{
    ui->setupUi(this);
    set_style();
}

lootonewidget::~lootonewidget()
{
    delete ui;
}

void lootonewidget::set_data(QString name, QString pix, QString about, int quality)
{
    pixmap.load(":/l/images/loot/"+pix.trimmed());
  ui->label->setText(name);
    ui->label_2->setPixmap(pixmap.scaledToHeight(QApplication::desktop()->screenGeometry().height()/3 - 30));

    ui->label_3->setText(quality == 1 ?"Обычная" : quality == 2 ? "Редкая": "ЛЕГЕНДАРНАЯ!!!!!" );
    ui->label_4->setText(about);
}

void lootonewidget::set_style()
{
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label_4->setAlignment(Qt::AlignCenter);
    ui->label_2->setMinimumHeight(QApplication::desktop()->screenGeometry().height()/2);
    ui->label_2->setMaximumHeight(QApplication::desktop()->screenGeometry().height()/2);
    ui->label_2->setMinimumWidth(QApplication::desktop()->screenGeometry().width()-40);
    ui->label_2->setMaximumWidth(QApplication::desktop()->screenGeometry().width()-40);
}

void lootonewidget::mouseReleaseEvent(QMouseEvent *me)
{
    emit signal_go_to_collection();
}
