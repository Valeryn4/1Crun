#include "core.h"


Core::Core(QObject *parent) : File(parent)
{
    proc1CRun = new QProcess(this);

    connect(this, SIGNAL(signal_1CRun(int)), this, SLOT(runProcess(int)));
    connect(this, SIGNAL(signal_1Cstop()), this, SLOT(engProcess()));
    connect(proc1CRun, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(engProcess()));
    connect(proc1CRun, SIGNAL(error(QProcess::ProcessError)), this, SLOT(engProcess()));

    //file = new File(this);
    shutdown = "\"shutdown\" -l -f ";

}

void Core::runProcess(int id) {
    if (!procRun) {
        proc1CRun ->start(path(id));
        procRun = true;
    }
}

void Core::engProcess() {
    proc1CRun->kill();
    proc1CRun->startDetached(shutdown);
}
