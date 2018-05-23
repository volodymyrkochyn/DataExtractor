#include "dataextractorapp.h"
#include "configuration.h"
#include "databaseinterface.h"
#include "modelserializer.h"

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
        for (auto table : _config.tables())
        {
            auto s = ModelSerializer(generateModel(table));
            s.serialize(_lastError);

            qDebug() << s.serializedData();
//            _models.append();
        }

        //MainSerializer s;

        return true;
    }

    return false;
}

QSqlQueryModel *DataExtractor::generateModel(const Table &table)
{
    auto model = new QSqlQueryModel;
    model->setQuery(QString("select %1 from %2;").arg(table.columns).arg(table.name));
    return model;
}
