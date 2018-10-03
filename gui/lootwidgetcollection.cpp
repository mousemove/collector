#include "lootwidgetcollection.h"
#include "ui_lootwidgetcollection.h"

lootwidgetcollection::lootwidgetcollection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lootwidgetcollection)
{
    frame = new QFrame(this);

    ui->setupUi(this);
    box =new QGridLayout(this);
    frame->setLayout(box);
    ui->scrollArea->setWidget(frame);
set_style();
    // connect()
}

lootwidgetcollection::~lootwidgetcollection()
{
    delete ui;
}

void lootwidgetcollection::refresh_collection(QVector<lootItem> *prizes)
{
    for(auto it: labels)
    {
        box->removeWidget( it);
        disconnect(it,SIGNAL(signal_open_full(lootItem)),this,SLOT(slot_open_full(lootItem)));
        delete it;

    }
    labels.clear();

    for(int i = 0; i < prizes->count();i++)
    {
        QLabel * label = new qlootlabel(prizes->at(i),this);

        label->setPixmap(prizes->at(i).count == 0 ? QPixmap(":/l/images/loot/undef.jpg").scaled(QApplication::desktop()->screenGeometry().width()/3 - 30,QApplication::desktop()->screenGeometry().height()/3) :
                                                    QPixmap(":/l/images/loot/"+prizes->at(i).pix.trimmed()).scaled(QApplication::desktop()->screenGeometry().width()/3 - 30,QApplication::desktop()->screenGeometry().height()/3) );
//            label->setStyleSheet("QLabel {"
//                                       "border-style: solid;"
//                                       "border-width: 5px;"
//                                       "border-color: red; "
//                                       "}");
        box->addWidget(label,  0 + i/3 ,i % 3);
      connect(label,SIGNAL(signal_open_full(lootItem)),this,SLOT(slot_open_full(lootItem)));
        labels.push_back(label);
    }



}

void lootwidgetcollection::resizeEvent(QResizeEvent *q)
{

}



void lootwidgetcollection::slot_open_full(lootItem item)
{

    if (ui->scrollArea->getIniMove() == 0)
    {
         if (item.count > 0) emit signal_open_full(item);
    }
    else
        ui->scrollArea->setIniMove(0);

}

void lootwidgetcollection::set_style()
{
    QFile file(":/qss/qss/pictureborder.qss");
    file.open(QFile::ReadOnly);
    styleSheet = QLatin1String(file.readAll());



    setStyleSheet(styleSheet);
}
