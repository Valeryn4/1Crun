#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QString>
#include <QList>
#include <QDir>
#include <QDebug>
#include <QSettings>

class File : public QObject
{
    Q_OBJECT
private:
    QList<QString> listPath;
    QList<QString> listName;


    bool readFile();
    bool creatFile();

protected:
    QSettings * config;
    QSettings * defaultConf;
    QString path(int line);
public:
    explicit File(QObject *parent = 0);
    QList<QString> getName();

signals:

public slots:
};

#endif // FILE_H
