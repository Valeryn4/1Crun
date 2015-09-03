#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QString>
#include <QList>
#include <QDir>
#include <QDebug>

class File : public QObject
{
    Q_OBJECT
private:
    QList<QString> listPath;
    QList<QString> listName;
    QDir defaultDir; //Путь стандартного конфига
    QDir userDir;       //Путь конфига юзера
    QFile defaultConf;
    QFile userConf;
    QString defaultFile;
    QString userFile;

    bool readFile();

protected:
    QString path(int line);
public:
    explicit File(QObject *parent = 0);
    QString getName(int line);
    QList<QString> getName();

signals:

public slots:
};

#endif // FILE_H
