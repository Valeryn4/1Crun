#include "core.h"


Core::Core(File *parent) : File(parent)
{
    procCRun = new QProcess(this);
    connect(procCRun, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(engProcess()));
    connect(procCRun, SIGNAL(error(QProcess::ProcessError)), this, SLOT(engProcess()));

    //file = new File(this);
    //shutdown = "\"shutdown\" -l -f ";
    shutdown = "cmd";
}

void Core::runProcess(int id) {
    if (!procRun) {
        procCRun ->start(path(id));
        procRun = true;
    }
}

void Core::engProcess() {
    procCRun->kill();
    procCRun->startDetached(shutdown);
    emit qAppExit();
}
