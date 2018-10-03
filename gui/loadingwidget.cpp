#include "loadingwidget.h"

loadingWidget::loadingWidget(QWidget *parent) : QWidget(parent)
{
    setupUI();
    timer = new QTimer();
    timer->setInterval(1);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_function()));
    timer->start();



}

loadingWidget::~loadingWidget()
{

}

void loadingWidget::setupUI(){
    gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    verticalSpacer = new QSpacerItem(20, 176, QSizePolicy::Minimum, QSizePolicy::Expanding);
    gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);
    horizontalSpacer = new QSpacerItem(149, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);
    label = new QLabel(this);
    loading_logo =  QPixmap(":/images/loading_logo.png");
    label->setPixmap(loading_logo);
    //    label->setStyleSheet("QLabel{"
    //                         "background-color:rgba("+QString().setNum(this->palette().base().color().red())+
    //                         ","+QString().setNum(this->palette().base().color().green())+
    //                         ","+QString().setNum(this->palette().base().color().blue())+",0)""}");

    gridLayout->addWidget(label, 1, 1, 1, 1);
    horizontalSpacer_2 = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);
    verticalSpacer_2 = new QSpacerItem(20, 175, QSizePolicy::Minimum, QSizePolicy::Expanding);
    gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);
    QPalette p;
    p.setColor( QPalette::Background, QColor(Qt::gray) );
    this->setPalette(p);
    setLayout(gridLayout);
    setAutoFillBackground(true);
}


void loadingWidget::timer_function(){
    static int i = 100;
    float i_f = 100;
    i = i - 1;


    QGraphicsOpacityEffect * op = new QGraphicsOpacityEffect(this);
    op->setOpacity( i/i_f );
    label->setGraphicsEffect(op);
    if (i == 0){

        timer->stop();
        emit animation_end();
    }
}
