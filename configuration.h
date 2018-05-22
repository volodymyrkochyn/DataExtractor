#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QString>
#include <QVector>

class Configuration
{
public:
    QString databasePath() const { return _databasePath; }
    void setDatabasePath(const QString &databasePath);

    QVector<QString> tables() const { return _tables; }
    void setTables(const QVector<QString> &tables);

private:
    QString _databasePath;
    QVector<QString> _tables;
};

#endif // CONFIGURATION_H
