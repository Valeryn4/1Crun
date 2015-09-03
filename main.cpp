#include "mainwindow.h"
#include "core/core.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Core Run1C;


    w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();

    return a.exec();
}
