#include "core.h"


Core::Core(File *parent) : File(parent)
{
    procStatus.clear();
    procRun = 0;
    for (int i = 0; i < 20; i++) {
        procCRun.push_back(new QProcess(this));
        procStatus[i] = SLEEP;
    }
   // connect(procCRun[id], SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(engProcess(int id)));
   // connect(procCRun[id], SIGNAL(error(QProcess::ProcessError)), this, SLOT(engProcess(int id)));

    shutdown = "\"shutdown\" -l -f ";
    //shutdown = "cmd";
}

void Core::runProcess(int id) {
    connect(procCRun[id], SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(engProcess()));
    connect(procCRun[id], SIGNAL(error(QProcess::ProcessError)), this, SLOT(engProcess()));
    if (!procCRun[id]->state() == QProcess::NotRunning) {
        qDebug() << "ERROR! Process RUNNING!";
    }
    else {
        procCRun[id]->start(path(id));

        if (!procCRun[id]->state() == QProcess::NotRunning) {
            procRun++;
            procStatus[id] = RUN;
        }
        else
            qDebug() << "Processes " << id << " no run!";
    }
    qDebug() << "Processes: " << procRun;
}

void Core::engProcess() {
    for (int i = 0; i < procCRun.size(); i++) {
        if (procStatus[i] == RUN && procCRun[i]->state() == QProcess::NotRunning) {
            procRun--;
            procCRun.remove(i);
            procStatus[i] = SLEEP;
            qDebug() << "Processes: " << procRun;
        }
    }
    qDebug() << "Processes: " << procRun;
    if (procRun <= 0)
        procCRun[0]->startDetached(shutdown);

}

void Core::killAllProcess() {
    for (int i = 0; i < procCRun.size(); i++) {
        if (!procCRun[i]->atEnd()) {
            procCRun[i]->kill();
            procRun++;
        }
    }
    procCRun[0]->startDetached(shutdown);
}

void Core::openConfig() {
    QString tempPath = "\"notepad\" ";
    tempPath.push_back(config->fileName());
    QProcess * open = new QProcess(this);
    open->startDetached(tempPath);
}
