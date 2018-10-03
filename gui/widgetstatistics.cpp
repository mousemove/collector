#include "widgetstatistics.h"
#include "ui_widgetstatistics.h"

widgetstatistics::widgetstatistics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgetstatistics)
{
    ui->setupUi(this);
    set_style();
}

widgetstatistics::~widgetstatistics()
{
    delete ui;
}

void widgetstatistics::set_stat(int money, int open, int common, int rare, int legendary)
{

    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label_4->setAlignment(Qt::AlignCenter);
    ui->label_5->setAlignment(Qt::AlignCenter);
    ui->label_6->setAlignment(Qt::AlignCenter);
    ui->label_7->setAlignment(Qt::AlignCenter);
    ui->label_8->setAlignment(Qt::AlignCenter);
    ui->label_9->setAlignment(Qt::AlignCenter);
    ui->label_10->setAlignment(Qt::AlignCenter);
    ui->label_5->setText(QString().setNum(open));
    ui->label_6->setText(QString().setNum(common));
    ui->label_7->setText(QString().setNum(rare));
    ui->label_8->setText(QString().setNum(legendary));
    ui->label_10->setText(QString().setNum(money));
}

void widgetstatistics::mouseReleaseEvent(QMouseEvent *me)
{
    emit    signal_go_back();
}

void widgetstatistics::set_style()
{
    QFile file(":/qss/qss/styleborderlabel.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
}


