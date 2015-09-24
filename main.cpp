#include "mainwindow.h"
#include "core/core.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //Программа
    Core RunC;

    //линки
    QObject::connect(&w, SIGNAL(signal_run(int)), &RunC, SLOT(runProcess(int)));
    QObject::connect(&w, SIGNAL(signal_exit()), &RunC, SLOT(killAllProcess()));
    QObject::connect(&w, SIGNAL(openConfig()), &RunC, SLOT(openConfig()));

    //интерфейс
    //Передаем имя кнопкам
    w.nameButton(RunC.getName());
    w.show();

    return a.exec();
}
