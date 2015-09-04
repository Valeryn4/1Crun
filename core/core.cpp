#include "core.h"


Core::Core(File *parent) : File(parent)
{
    procRun = false;
    procCRun = new QProcess(this);
    connect(procCRun, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(engProcess()));
    connect(procCRun, SIGNAL(error(QProcess::ProcessError)), this, SLOT(engProcess()));

    shutdown = "\"shutdown\" -l -f ";
    //shutdown = "cmd";
}

void Core::runProcess(int id) {
    if (!procRun) {
        procCRun->start(path(id));
        procRun = true;
    }

}

void Core::engProcess() {
    procCRun->kill();
    procCRun->startDetached(shutdown);

}

void Core::openConfig() {
    QString tempPath = "\"notepad\" ";
    tempPath.push_back(config->fileName());
    QProcess * open = new QProcess(this);
    open->startDetached(tempPath);
}
