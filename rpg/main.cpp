#include "mainwindow.h"
#include <QApplication>
#include "mw.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MW d;
    d.show();
    QObject::connect(&d,SIGNAL(showmainwindow()),&w,SLOT(receiveBegin()));
    QObject::connect(&d,SIGNAL(quit()),&a,SLOT(quit()));
    QObject::connect(&w,SIGNAL(showEnterDialog()),&d,SLOT(receiveEnter()));

    return a.exec();
}
