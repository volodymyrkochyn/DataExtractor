#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QString>
#include <QVector>

struct Table
{
    QString name;
    QString columns;
    Table(const QString &n, const QString &c) : name(n), columns(c) {}
    Table() =default;
};

class Configuration
{
public:
    QString databasePath() const { return _databasePath; }
    void setDatabasePath(const QString &databasePath);

    QVector<Table> tables() const { return _tables; }
    void appendTable(const Table &t);

private:
    QString _databasePath;
    QVector<Table> _tables;
};

#endif // CONFIGURATION_H
