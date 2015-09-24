#ifndef CORE_H
#define CORE_H

#include "file.h"
#include <QProcess>
#include <QVector>
#include <QMap>

enum pStatus {
    RUN,
    SLEEP
};

class Core : public File
{
    Q_OBJECT
private:
    QMap<int, pStatus> procStatus;
    QVector<QProcess*> procCRun;
    int procRun;
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
    void killAllProcess();
};

#endif // CORE_H
