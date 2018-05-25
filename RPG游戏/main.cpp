//#include "mainwindow.h"
#include "mw1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    MW1 mw;
    mw.show();//此处设置人遇到石头时不能走动，遇到花时吃掉，其余可以通过。

    return a.exec();
}
