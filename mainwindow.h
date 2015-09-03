#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

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
    ~MainWindow();
signals:
    void signal_run(int n);
private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();

public slots:

};

#endif // MAINWINDOW_H
