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
    //shutdown = "\"shutdown\" -l -f";
    shutdown = " ";
    ui->pushButton_1->setText(this->getName(1));
    ui->pushButton_2->setText(this->getName(2));
    ui->pushButton_3->setText(this->getName(3));
    ui->pushButton_4->setText(this->getName(4));
    ui->pushButton_5->setText(this->getName(5));
    ui->pushButton_6->setText(this->getName(6));
    ui->pushButton_7->setText(this->getName(7));
    ui->pushButton_8->setText(this->getName(8));
    ui->pushButton_8->setText(this->getName(9));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_exit_clicked()
{
    qApp->exit();
}

QString MainWindow::getName(int index) {
    QString name;
    QString temp = path[index];
    name.clear();
    if (temp.size() < 5)
        return "...";
    for (int i = 2; temp.at(i) != '|' && i < temp.size() && temp.at(i) != '\n'; i++) {
        name.push_back(temp.at(i));

    }
    if (name.size() > 15)
        return "ERROR SIZE NAME";
    return name;
}

void MainWindow::run1C(int index) {
    bool flag = false;
    QString path_;
    QString pathlist = path[index];
    pathlist.clear();

    if (pathlist.size() > 5) {
        for (int i = 0; i < pathlist.size() ; i++)
            if (pathlist.at(i) == '|' && flag == false) {
                flag = true;
                i++;
            } else if (flag == true) {
                if (pathlist.at(i) == '\n')
                    break;
                path_.push_back(pathlist.at(i));
            }
    } else {
        path_ = "";
    }


    run.start(path_);
    this->hide();
    run.waitForFinished();
    run.kill();
    run.start(shutdown);
    run.waitForFinished();
    qApp->exit();

}


void MainWindow::on_pushButton_1_clicked()
{
    run1C(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    run1C(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    run1C(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    run1C(4);
}

void MainWindow::on_pushButton_5_clicked()
{
    run1C(5);
}

void MainWindow::on_pushButton_6_clicked()
{
    run1C(6);
}

void MainWindow::on_pushButton_7_clicked()
{
    run1C(7);
}

void MainWindow::on_pushButton_8_clicked()
{
    run1C(8);
}

void MainWindow::on_pushButton_9_clicked()
{
    run1C(9);
}
