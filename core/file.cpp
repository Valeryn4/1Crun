#include "file.h"

File::File(QObject *parent) : QObject(parent) {
    QDir dir;
    dir.current();

    QString defConfPath = dir.filePath("default.ini");
    defaultConf = new QSettings(defConfPath, QSettings::IniFormat, this);
    config = new QSettings(QSettings::IniFormat, QSettings::UserScope, "1CRun", "config", this);

    if(!QFile::exists(defaultConf->fileName()))
        if(!creatFile()) {
            qWarning("Failed create default.ini");
        }
    if(!readFile()) {
        qWarning("Failed read config.ini");
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
    return true;
}

bool File::readFile() {
    listPath.clear();
    listName.clear();
    if (QFile::exists(config->fileName())) {
        if (defaultConf->value("system/version").toInt() > config->value("system/version").toInt()) {
           QFile(config->fileName()).remove();
           if (!QFile::copy(defaultConf->fileName(), config->fileName())) {
               qDebug() << "fail copy default.ini to config.ini";
               return false;
           }
        }
    } else {
        if (!QFile::copy(defaultConf->fileName(), config->fileName())) {
            qDebug() << "fail copy default.ini to config.ini";
            return false;
        }
    }

    int n;
    n = config->value("system/buttons").toInt();
    config->beginReadArray("Button");
    for (int i = 0; i < n; i++) {
        config->setArrayIndex(i);
        listName << config->value("name").toString();
        listPath << config->value("path").toString();
    }
    config->endArray();
    return true;
}


QList<QString> File::getName() {
    return listName;
}

QString File::path(int line) {
    return listPath[line];
}

