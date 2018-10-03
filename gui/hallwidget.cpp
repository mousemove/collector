#include "hallwidget.h"
#include "ui_hallwidget.h"

void hallwidget::setCorrectNumber(int value)
{
    int massiv[4] = {0};
    correctNumber = value;
    massiv[0] = rand() % 31 + 30;
    massiv[1] = rand() % (100-massiv[0]);
    massiv[2] = rand() % (100-(massiv[0]+massiv[1]));
    massiv[3] = (100-(massiv[0]+massiv[1]+massiv[2]));

    switch (value) {
    case 1:
        ui->label_6->setText(QString().setNum(massiv[0])+" %");
        ui->label_7->setText(QString().setNum(massiv[1])+" %");
        ui->label_8->setText(QString().setNum(massiv[2])+" %");
        ui->label_9->setText(QString().setNum(massiv[3])+" %");
        break;
    case 2:
        ui->label_6->setText(QString().setNum(massiv[1])+" %");
        ui->label_7->setText(QString().setNum(massiv[0])+" %");
        ui->label_8->setText(QString().setNum(massiv[2])+" %");
        ui->label_9->setText(QString().setNum(massiv[3])+" %");
        break;
    case 3:
        ui->label_6->setText(QString().setNum(massiv[2])+" %");
        ui->label_7->setText(QString().setNum(massiv[1])+" %");
        ui->label_8->setText(QString().setNum(massiv[0])+" %");
        ui->label_9->setText(QString().setNum(massiv[3])+" %");
        break;
    case 4:
        ui->label_6->setText(QString().setNum(massiv[3])+" %");
        ui->label_7->setText(QString().setNum(massiv[1])+" %");
        ui->label_8->setText(QString().setNum(massiv[2])+" %");
        ui->label_9->setText(QString().setNum(massiv[0])+" %");
        break;

    }

}

void hallwidget::mousePressEvent(QMouseEvent *e)
{
 emit signal_exit_hall();
}



hallwidget::hallwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hallwidget)
{
    ui->setupUi(this);
    set_style();
}

hallwidget::~hallwidget()
{
    delete ui;
}

void hallwidget::set_style()
{
    QFile file(":/qss/qss/style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
    ui->label_10->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignCenter);
    QPixmap pixmap = QPixmap(":/images/audience2.jpg").scaledToHeight(QApplication::desktop()->screenGeometry().height()/5);
    ui->label_10->setPixmap(pixmap);
}
