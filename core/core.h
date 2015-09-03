#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <QProcess>

class core : public QObject
{
    Q_OBJECT
public:
    explicit core(QObject *parent = 0);

signals:

public slots:
};

#endif // CORE_H
