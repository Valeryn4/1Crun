#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QString>
#include <QList>
#include <QDir>

class File : public QObject
{
    Q_OBJECT
private:
    QList<QString> listPath;
    QList<QString> listName;
    QDir defaultDir = QDir::current(); //Путь стандартного конфига
    QDir userDir = QDir::home();       //Путь конфига юзера
    QFile defaultConf;
    QFile userConf;
    QString defaultFile = "default.txt";
    QString userFile = "conf.txt";

    bool readFile();

protected:
    explicit file(QObject *parent = 0);

    QString path(int line);

signals:
    QString name(int line);

public slots:
};

#endif // FILE_H
