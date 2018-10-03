#include "aboutwidget.h"
#include "ui_aboutwidget.h"

aboutWidget::aboutWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aboutWidget)
{
    ui->setupUi(this);
    set_style();
}

aboutWidget::~aboutWidget()
{
    delete ui;
}

void aboutWidget::set_style()
{
    QFile file(":/qss/qss/style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
}

void aboutWidget::mouseReleaseEvent(QMouseEvent *me)
{
    emit signal_go_back();
}
