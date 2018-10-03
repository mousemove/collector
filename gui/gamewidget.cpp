#include "gamewidget.h"
#include "ui_gamewidget.h"
#include <algorithm>



gamewidget::gamewidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamewidget)
{
    ui->setupUi(this);
    questionbutton.push_back(ui->pushButton_5);
    questionbutton.push_back(ui->pushButton_6);
    questionbutton.push_back(ui->pushButton_7);
    questionbutton.push_back(ui->pushButton_8);
    //Загрузка каскадных стилей


    for(auto it =  questionbutton.begin(); it !=  questionbutton.end(); ++it)
    {
        connect(*it,SIGNAL(clicked()),this,SLOT(slot_button_clicked()));
    }
    timer.setInterval(200);//5 герц
    connect(&timer,SIGNAL(timeout()),this,SLOT(slot_for_timer()));

    set_style();


    // Выставление стилей

}

gamewidget::~gamewidget()
{
    delete ui;
}

void gamewidget::refresh_data( )
{

}




void gamewidget::slot_from_logic(QString question, QString pix, QString * list, int correct, bool * hints, int money,int number)
{
    QTime midnight(0,0,0);
    srand(midnight.secsTo(QTime::currentTime()));
    ui->label->setText(question);
    if (pix != ""){
        QString d = ":/q/images/questions/"+pix;
        QPixmap pixmap =  QPixmap(d.trimmed()).scaledToHeight(QApplication::desktop()->screenGeometry().height()/4);

        //ui->label_2->setPixmap(pixmap);
        ui->label_2->set_pix(pixmap);

    }
    else{
        QString d = ":/images/quest.png";
        QPixmap pixmap =  QPixmap(d.trimmed()).scaledToHeight(QApplication::desktop()->screenGeometry().height()/4);
    ui->label_2->off_pix();
        ui->label_2->setPixmap(pixmap);

    }
    //Заполнение кнопок
    std::random_shuffle(questionbutton.begin(),questionbutton.end());
    for(int i = 0;i < 4;i++)
    {
        questionbutton.at(i)->setText(list[i]);
        questionbutton.at(i)->setEnabled(true);
        if(i+1 == correct)
        {
            correctButton = questionbutton.at(i);
            //questionbutton.at(i)->setStyleSheet(styleSheetGreenButton);
        }
    }
    corButtNumber = 0;

    if (ui->pushButton_5== correctButton) corButtNumber = 1;
    if (ui->pushButton_6== correctButton) corButtNumber = 2;
    if (ui->pushButton_7== correctButton) corButtNumber = 3;
    if (ui->pushButton_8== correctButton) corButtNumber = 4;


    ui->pushButton_5->setText("А "+ui->pushButton_5->text());
    ui->pushButton_6->setText("Б "+ui->pushButton_6->text());
    ui->pushButton_7->setText("В "+ui->pushButton_7->text());
    ui->pushButton_8->setText("Г "+ui->pushButton_8->text());
    ui->pushButton->setEnabled(hints[fiftyfifty]);
    ui->pushButton_2->setEnabled(hints[call]);
    ui->pushButton_3->setEnabled(hints[hall]);
     ui->pushButton_4->setEnabled(true);
    ui->label_3->setText("<center>Вопрос на "+QString().setNum(money)+" БАКСОВ!!!!</center>");
    for(auto it =  questionbutton.begin(); it !=  questionbutton.end(); ++it)
    {
        (*it)->setEnabled(true);

        (*it)->setStyleSheet(styleSheetNoSelectButton);
    }
    qMoney = money;
    qNumber = number;

    emit signal_ready();
}

void gamewidget::slot_button_clicked()
{
    QPushButton * button = static_cast<QPushButton *> (sender());
    for(auto it =  questionbutton.begin(); it !=  questionbutton.end(); ++it)
    {
        (*it)->setEnabled(false);
    }
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
    selectedButton = button;
    timer.start();

}

void gamewidget::slot_for_timer()
{
    static int i = 0;

    if (i > 10) correctButton->setStyleSheet(styleSheetGreenButton);
    if(selectedButton != correctButton || i <= 10 )
        selectedButton->setStyleSheet( selectedButton->styleSheet() ==   styleSheetNoSelectButton ? styleSheetOrangeButton : styleSheetNoSelectButton  );

    i++;

    if (i > 12)
    {
        timer.stop();

        emit signal_result(selectedButton == correctButton);
        i = 0;
    }
}

void gamewidget::on_pushButton_clicked()
{
    int counter = 0;
    QPushButton * fst = nullptr;
    while ( (counter < 2))
    {
        int tmpRand = rand() % 4;
        if (questionbutton.at(tmpRand) != correctButton && questionbutton.at(tmpRand) != fst )
        {
            questionbutton.at(tmpRand)->setText("");
            questionbutton.at(tmpRand)->setEnabled(false);
            fst = questionbutton.at(tmpRand);
            counter++;
        }
    }
    ui->pushButton->setEnabled(false);
    emit signal_activate_hint(fiftyfifty);
}

void gamewidget::on_pushButton_2_clicked()
{
    ui->pushButton_2->setEnabled(false);
    emit signal_activate_hint(call);

    emit signal_call_hint(corButtNumber);
}

void gamewidget::on_pushButton_3_clicked()
{
    ui->pushButton_3->setEnabled(false);
    emit signal_activate_hint(hall);
    emit signal_hall_hint(corButtNumber);
}

void gamewidget::on_pushButton_4_clicked()
{
    emit signal_took();
}


void gamewidget::set_style()
{
    styleSheetNoSelectButton = ui->pushButton_5->styleSheet();
    QFile fileG(":/qss/qss/sbg.qss");
    fileG.open(QFile::ReadOnly);
    styleSheetGreenButton = QLatin1String(fileG.readAll());

    QFile fileY(":/qss/qss/sby.qss");
    fileY.open(QFile::ReadOnly);
    styleSheetOrangeButton = QLatin1String(fileY.readAll());


    QFile file(":/qss/qss/style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
    ui->pushButton->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_2->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_3->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_4->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_5->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_6->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_7->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_8->setFocusPolicy(Qt::NoFocus);
    ui->pushButton->setMinimumHeight(QApplication::desktop()->screenGeometry().height()/8);
    ui->pushButton_2->setMinimumHeight(QApplication::desktop()->screenGeometry().height()/8);
    ui->pushButton_3->setMinimumHeight(QApplication::desktop()->screenGeometry().height()/8);
    ui->pushButton_4->setMinimumHeight(QApplication::desktop()->screenGeometry().height()/8);
    ui->pushButton_5->setMinimumHeight(QApplication::desktop()->screenGeometry().height()/8);
    ui->pushButton_6->setMinimumHeight(QApplication::desktop()->screenGeometry().height()/8);
    ui->pushButton_7->setMinimumHeight(QApplication::desktop()->screenGeometry().height()/8);
    ui->pushButton_8->setMinimumHeight(QApplication::desktop()->screenGeometry().height()/8);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label->setMinimumHeight(QApplication::desktop()->screenGeometry().height()/3);
    ui->label_2->setMaximumHeight(QApplication::desktop()->screenGeometry().height()/4);

    QFile filebigbutton(":/qss/qss/sbbigbutton.qss");
    filebigbutton.open(QFile::ReadOnly);
    QString styleSheetfilebigbutton = QLatin1String(filebigbutton.readAll());
    ui->pushButton->setStyleSheet(styleSheetfilebigbutton);
    ui->pushButton_2->setStyleSheet(styleSheetfilebigbutton);
        ui->pushButton_3->setStyleSheet(styleSheetfilebigbutton);
            ui->pushButton_4->setStyleSheet(styleSheetfilebigbutton);

}
