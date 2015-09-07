#include "file.h"

File::File(QObject *parent) : QObject(parent) {
    QDir dir;
    dir = dir.current();

    defaultConf = new QSettings(dir.filePath("default.ini"), QSettings::IniFormat);
    config = new QSettings(QSettings::IniFormat, QSettings::UserScope, "1CRun", "config");
    if(!QFile::exists(defaultConf->fileName()))
        if(!creatFile()) {
            qDebug() << "Failed create default.ini. ERROR " << defaultConf->status();
        }
    if(!readFile()) {
        qDebug() << "Failed read config.ini";
    }

}

bool File::creatFile() {
    int n;

    //[system]
    defaultConf->setValue("system/version", 1);
    defaultConf->setValue("system/title", "1C");
    defaultConf->setValue("system/buttons", 19);

    //[Button]
    n = defaultConf->value("system/buttons").toInt();
    defaultConf->beginWriteArray("Button");
    for (int i = 0; i < n; i++) {
        defaultConf->setArrayIndex(i);
        defaultConf->setValue("name", "name");
        defaultConf->setValue("path", " ");
    }
    defaultConf->endArray();
    defaultConf->sync();
    if (defaultConf->status() != 0)
        return false;
    return true;
}

bool File::readFile() {
    listPath.clear();
    listName.clear();
    if (QFile::exists(config->fileName())) {
        if (defaultConf->value("system/version").toInt() > config->value("system/version").toInt()) {
           QFile(config->fileName()).remove();
           if (!QFile::copy(defaultConf->fileName(), config->fileName())) {
               qDebug() << "fail copy default.ini to config.ini 47";
               return false;
           }
        }
    } else {
        if (!QFile::copy(defaultConf->fileName(), config->fileName())) {
            qDebug() << "fail copy default.ini to config.ini 53";
            return false;
        }
    }
    config->sync();
    int n;
    n = config->value("system/buttons").toInt();
    config->beginReadArray("Button");
    for (int i = 0; i < n; i++) {
        config->setArrayIndex(i);
        listName << config->value("name").toString();
        listPath << config->value("path").toString();
    }
    config->endArray();
    qDebug() << listPath[1];
    return true;
}


QList<QString> File::getName() {
    return listName;
}

QString File::path(int line) {
    return listPath[line];
}

