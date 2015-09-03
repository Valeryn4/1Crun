#include "mainwindow.h"
#include "core/core.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Core RunC;
    QObject::connect(&w, SIGNAL(signal_run(int)), &RunC, SLOT(runProcess(int)));
    QObject::connect(&w, SIGNAL(signal_exit()), &RunC, SLOT(engProcess()));
    QObject::connect(&w, SIGNAL(openConfig()), &RunC, SLOT(openConfig()));

    w.nameButton(RunC.getName());
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();

    return a.exec();
}
