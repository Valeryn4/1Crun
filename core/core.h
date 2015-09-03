#ifndef CORE_H
#define CORE_H

#include "file.h"
#include <QProcess>


class Core : public File
{
    Q_OBJECT
private:
    //File * file;
    QProcess * procCRun;
    bool procRun;
    QString shutdown;

public:
    explicit Core(File *parent = 0);

signals:
    void signal_CRun(int n);
    void signal_Cstop();
    void qAppExit();

private slots:
    void runProcess(int n);
    void engProcess();
};

#endif // CORE_H
