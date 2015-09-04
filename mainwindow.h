#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QDebug>
#include <QEvent>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
public:
    explicit MainWindow(QWidget *parent = 0);
    void nameButton(QList<QString> list);
    virtual void closeEvent(QCloseEvent *event);
    ~MainWindow();
signals:
    void signal_run(int n);
    void signal_exit();
    void openConfig();
private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

public slots:

};

#endif // MAINWINDOW_H
