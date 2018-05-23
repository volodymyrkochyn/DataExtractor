#include "configuration.h"

void Configuration::setDatabasePath(const QString &databasePath)
{
    _databasePath = databasePath;
}

void Configuration::appendTable(const Table &t)
{
    _tables.append(t);
}
