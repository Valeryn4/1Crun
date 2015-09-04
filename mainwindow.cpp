#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nameButton(QList<QString> list) {
    ui->pushButton_1->setText(list[1]);
    ui->pushButton_2->setText(list[2]);
    ui->pushButton_3->setText(list[3]);
    ui->pushButton_4->setText(list[4]);
    ui->pushButton_5->setText(list[5]);
    ui->pushButton_6->setText(list[6]);
    ui->pushButton_7->setText(list[7]);
    ui->pushButton_8->setText(list[8]);
    ui->pushButton_9->setText(list[9]);
}



void MainWindow::on_pushButton_exit_clicked()
{
    emit signal_exit();
    qApp->exit();
}

void MainWindow::on_pushButton_clicked()
{
    emit openConfig();
}

void MainWindow::on_pushButton_1_clicked() { emit signal_run(1); }
void MainWindow::on_pushButton_2_clicked() { emit signal_run(2); }
void MainWindow::on_pushButton_3_clicked() { emit signal_run(3); }
void MainWindow::on_pushButton_4_clicked() { emit signal_run(4); }
void MainWindow::on_pushButton_5_clicked() { emit signal_run(5); }
void MainWindow::on_pushButton_6_clicked() { emit signal_run(6); }
void MainWindow::on_pushButton_7_clicked() { emit signal_run(7); }
void MainWindow::on_pushButton_8_clicked() { emit signal_run(8); }
void MainWindow::on_pushButton_9_clicked() { emit signal_run(9); }

