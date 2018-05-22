#ifndef DATAEXTRACTORAPP_H
#define DATAEXTRACTORAPP_H

#include "configuration.h"

#include <QString>
#include <memory>

class DatabaseInterface;

class DataExtractor
{
public:
    DataExtractor(const Configuration &config, const std::shared_ptr<DatabaseInterface> &db);
    QString lastError() const { return _lastError; }

    bool process();

private:
    QString _lastError;
    Configuration _config;
    std::shared_ptr<DatabaseInterface> _database{nullptr};
};

#endif // DATAEXTRACTORAPP_H
