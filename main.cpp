#include "router.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    router w;
    w.setMinimumHeight(QApplication::desktop()->screenGeometry().height());
    w.setMaximumHeight(QApplication::desktop()->screenGeometry().height());
    w.setMinimumWidth(QApplication::desktop()->screenGeometry().width());
    w.setMaximumWidth(QApplication::desktop()->screenGeometry().width());
    w.showFullScreen();

    return a.exec();
}
