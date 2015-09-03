#ifndef CORE_H
#define CORE_H

#include "file.h"
#include <QProcess>


class Core : public File
{
    Q_OBJECT
private:
    //File * file;
    QProcess * proc1CRun;
    bool procRun;
    QString shutdown;

public:
    explicit core(File *parent = 0);

signals:
    void signal_1CRun(int n);
    void signal_1Cstop();

private slots:
    void runProcess(int n);
    void engProcess();
};

#endif // CORE_H
