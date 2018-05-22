#include "configuration.h"

void Configuration::setDatabasePath(const QString &databasePath)
{
    _databasePath = databasePath;
}

void Configuration::setTables(const QVector<QString> &tables)
{
    _tables = tables;
}
