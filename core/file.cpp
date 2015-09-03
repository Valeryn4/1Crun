#include "file.h"

File::File(QObject *parent) : QObject(parent) {
    defaultDir = QDir::current(); //Путь стандартного конфига
    userDir = QDir::home();       //Путь конфига юзера
    defaultFile = "default.txt";
    userFile = "conf.txt";
    //chek
    qDebug() << "Default dir" << defaultDir.filePath(defaultFile);
    qDebug() << "User Dir" << userDir.filePath(userFile);

    //setup userDir
    if (!userDir.cd("AppData")) {
        qWarning("No Dirrectory AppData");
    }
    else if (!userDir.cd("Roaming")) {
        qWarning("No Dirrectory AppData/Roaming");
    }
    else if (!userDir.cd("1CRun")) {
        qDebug() << "No 1CRun dir";
        if (!userDir.mkdir("1CRun"))
            qWarning("ERROR create mkdir 1CRun in AppData/Roaming");
    }
    userConf.setFileName(userDir.filePath(userFile));
    defaultConf.setFileName(defaultDir.filePath(defaultFile));
    if (!userConf.exists()) {
        qDebug() << "File conf.txt no found";
        if (!QFile::copy(defaultDir.filePath(defaultFile), userDir.filePath(userFile)))
            qWarning("ERROR copy file");
    }
    if (!readFile())
        qWarning("readFile() Error, return false");
}

bool File::readFile() {
    bool flag_empty;
    bool flag_name;
    bool flag_path;
    int line;
    QString tempLine;
    QString tempName;
    QString tempPath;
    listName.clear();
    listPath.clear();
    if (!userConf.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error open conf.txt";
        qWarning("Error open conf.txt");
        userConf.close();
        return false;
    } else
    // [0] "name" <path/to/file.exe>
    //  ^     ^         ^
    //index   |         |
    //     name button  |
    //              path to file
    //  #hello
    //  ^
    //commit
    while (!userConf.atEnd()) {
        line = 0;
        flag_empty = false;
        flag_name = false;
        flag_path = false;
        tempName.clear();
        tempPath.clear();
        tempLine.clear();
        tempLine.push_back(userConf.readLine());
        for (int i = 0; i < tempLine.size() && tempLine.at(i) != '\n' && tempLine.at(i) != '#'; i++) {
            if (tempLine.at(i) == '[' && flag_name == false && flag_path == false && flag_empty == false)
                flag_empty = true;
            else if (flag_empty == true){
                if (tempLine.at(i) == ']' )
                    flag_empty = false;
                else if (tempLine.at(i) == '\n') {
                    qWarning("ERROR! Conf file no close \"]\"");
                    qDebug() << "ERROR! Conf file no close \"]\"";
                    userConf.close();
                    return false;
                }
            }
            else if (tempLine.at(i) == '\"' && flag_path == false && flag_name == false && flag_empty == false)
                flag_name = true;
            else if (tempLine.at(i) != '\"' && flag_name == true)
                tempName.push_back(tempLine.at(i));
            else if (tempLine.at(i) == '\"' && flag_name == true)
                flag_name = false;
            else if (tempLine.at(i) == '\n' && flag_name == true) {
                qWarning("ERROR! Conf file no close name \"");
                qDebug() << "ERROR! Conf file no close name \"";
                userConf.close();
                return false;
            }
            else if (tempLine.at(i) == '<' && line != 0 && flag_path == false && flag_name == false && flag_empty == false)
                flag_path = true;
            else if (tempLine.at(i) != '>' && flag_path == true)
                tempPath.push_back(tempLine.at(i));
            else if (tempLine.at(i) == '>' && flag_path == true)
                flag_path = false;
            else if (tempLine.at(i) == '\n' && flag_path == true) {
                qWarning("ERROR! Conf file no close name >");
                qDebug() << "ERROR! Conf file no close name >";
                userConf.close();
                return false;
            }        
        }
        qDebug() << tempName;
        listName << tempName;
        qDebug() << tempPath;
        listPath << tempPath;
    }
    userConf.close();
    return true;
}

QString File::getName(int line) {
    qDebug() << "return: " <<  listName[line];
    return listName[line];
}

QList<QString> File::getName() {
    return listName;
}

QString File::path(int line) {
    qDebug() << "return: " << listPath[line];
    return listPath[line];
}

