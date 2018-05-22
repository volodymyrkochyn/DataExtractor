#include "dataextractorapp.h"
#include "configuration.h"
#include "databaseinterface.h"

#include <QDebug>

#include <QSqlTableModel>

DataExtractor::DataExtractor(const Configuration &config,
                             const std::shared_ptr<DatabaseInterface> &db)
    : _config(config),
      _database(db)
{
}

bool DataExtractor::process()
{
    if (_database && _database->connect(_lastError))
    {
        return true;
    }

    return false;
}
