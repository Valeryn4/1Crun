#ifndef CORE_H
#define CORE_H

#include "file.h"
#include <QProcess>


class Core : public File
{
    Q_OBJECT
private:
    QProcess * procCRun;
    bool procRun;
    QString shutdown;

public:
    explicit Core(File *parent = 0);

signals:
   // void signal_CRun(int n);
   // void signal_Cstop();

public slots:
    void runProcess(int n);
    void openConfig();
    void engProcess();
};

#endif // CORE_H
