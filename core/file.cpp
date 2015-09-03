#include "file.h"

File::File(QObject *parent) : QObject(parent) {
    //chek
    qDebug() << "Default dir" << defaultDir.filePath(defaultFile);
    qDebug() << "User Dir" << userDir.filePath(userFile);

    //setup userDir
    if (!userDir.cd("AppData")) {
        qWarning("No Dirrectory %AppData%");
        qDebug() << "cd dir AppData: " << userDir.cd(AppData);
    }
    else if (!userDir.cd("Roaming")) {
        qWarning("No Dirrectory %AppData%/Roaming");
        qDebug() << "cd dir AppData/Roaming: " << userDir.cd(Roaming);
    }
    else if (!userDir.cd("1CRun")) {
        qDebug() << "No 1CRun dir";
        if (!userDir.mkdir("1CRun"))
            qWarning("ERROR create mkdir 1CRun in AppData/Roaming");
    }
    userConf.setFileName(userDir.filePath(userFile));
    defaultConf.setFileName(defaultDir.filePath(defaultFile));
    //chek
    qDebug() << "Default dir" << defaultDir.filePath(defaultFile);
    qDebug() << "User Dir" << userDir.filePath(userFile);

    if (!userConf.exists()) {
        qDebug() << "File conf.txt no found";
        if (!QFile::copy(defaultDir.filePath(defaultFile), userDir.filePath(userFile)))
            qWarning("ERROR copy file" + defaultDir.filePath(defaultFile) + "to " + userDir.filePath(userFile));
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
        qWarning("Error open conf.txt");
        return false;
    }
    // [0] "name" <path/to/file.exe>
    //  ^     ^         ^
    //index   |         |
    //     name button  |
    //              path to file
    while (userConf.atEnd()) {
        line = 0;
        flag_empty = false;
        flag_name = false;
        flag_path = false;
        tempName.clear();
        tempPath.clear();
        tempLine = userConf.readLine();
        for (int i = 0; i < tempLine.size() || tempLine.at(i) == '\n'; i++) {
            if (tempLine.at(i) == '#') {}
            else if (tempLine.at(i) == '[' && flag_name == false && flag_path == false && flag_empty = false)
                flag_empty = true;
            else if (flag_empty == true){
                if (tempLine.at(i) == ']' )
                    flag_empty = false;
                else if (tempLine.at(i+1) == '\n') {
                    qWarning("ERROR! Conf file no close \"]\"");
                    return false;
                }
            }
            else if (tempLine.at(i) == '\"' && flag_path == false && flag_name == false && flag_empty = false)
                flag_name = true;
            else if (tempLine.at(i) != '\"' && flag_name == true)
                tempName.push_back(tempLine.at(i));
            else if (tempLine.at(i) == '\"' && flag_name == true)
                flag_name == false;
            else if (tempLine.at(i+1) == '\n' && flag_name == true) {
                qWarning("ERROR! Conf file no close name \"");
                return false;
            }
            else if (tempLine.at(i) == '<' && line != 0 && flag_path == false && flag_name == false && flag_empty = false)
                flag_path == true;
            else if (tempLine.at(i) != '>' && flag_path == true)
                tempPath.push_back(tempLine.at(i));
            else if (tempLine.at(i) == '>' && flag_path == true)
                flag_path == false;
            else if (tempLine.at(i+1) == '\n' && flag_path == true) {
                qWarning("ERROR! Conf file no close name >");
                return false;
            }
            if (tempName.size() < 3)
                listName = "...";
            if (tempPath.size() < 1)
                listName = " ";
            listName << tempName;
            listPath << tempPath;
        }
    }
    userConf.close();

}

QString File::name(int line) {
    qDebug() << "return: " <<  listName[line];
    return listName[line];
}

QString File::path(int line) {
    qDebug() << "return: " << listPath[line];
    return listPath[line];
}

