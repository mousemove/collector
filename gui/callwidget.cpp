#include "callwidget.h"
#include "ui_callwidget.h"

void callwidget::setCorrectNumber(int value)
{
    int chararter = rand() % count_characters;
    correctNumber = value;
    int i = rand() % 100;
    if (i > brainlevel[chararter]) value = value == 1? 2 : value == 2 ? 3 : value == 3? 4 : value == 4 ? 1 : value;


    pix.load(faces[chararter]);

    ui->label_2->set_pix(pix.scaledToHeight(QApplication::desktop()->screenGeometry().height()/2));
    ui->label->setText(quotes[chararter].replace(quotes[chararter].indexOf("ANSWER"), QString("ANSWER").size(),value == 1? "А" : value == 2 ? "Б" : value == 3? "В" : value == 4 ? "Г" : "А"  ));
    ui->label_3->setText("Абонент <b>"+names[chararter]+"</b>");
}



callwidget::callwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::callwidget)
{
    ui->setupUi(this);
    QPixmap pixmap = QPixmap(":/images/phone.png").scaledToHeight(QApplication::desktop()->screenGeometry().height()/5);
    ui->label_4->setPixmap(pixmap);
    set_style();

}

callwidget::~callwidget()
{
    delete ui;
}

void callwidget::mousePressEvent(QMouseEvent *e)
{
    emit signal_exit_call();
}


void callwidget::set_style()
{
    QFile file(":/qss/qss/style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_3->setAlignment(Qt::AlignCenter);
//    QFile filep(":/qss/qss/pictureborder.qss");
//    filep.open(QFile::ReadOnly);
//    QString styleSheetP = QLatin1String(filep.readAll());
//    ui->label-> setStyleSheet(styleSheetP);
}
