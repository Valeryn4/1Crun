#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    path.clear();
    QFile filePath;
    filePath.setFileName("C:\\run1C\\path.txt");
    if (filePath.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Open";
        while(!filePath.atEnd()) {
            path << filePath.readLine();
        }
        filePath.close();
    } else {
        qDebug() << "can't open account list";
    }
    shutdown = "\"shutdown\" -l -f";
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::run1C(QString path_) {
    run.start(path_);
    run.waitForFinished();
    run.kill();
    run.start(shutdown);
    run.waitForFinished();
    qApp->exit();
}


void MainWindow::on_pushButton_exit_clicked()
{
    qApp->exit();
}

void MainWindow::on_pushButton_1_clicked()
{
    run1C(path[0]);
}

void MainWindow::on_pushButton_2_clicked()
{
    run1C(path[1]);
}

void MainWindow::on_pushButton_3_clicked()
{
    run1C(path[2]);
}

void MainWindow::on_pushButton_4_clicked()
{
    run1C(path[3]);
}

void MainWindow::on_pushButton_5_clicked()
{
    run1C(path[4]);
}

void MainWindow::on_pushButton_6_clicked()
{
    run1C(path[5]);
}
