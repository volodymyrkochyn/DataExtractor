#ifndef SQLITEDATABASECONNECTION_H
#define SQLITEDATABASECONNECTION_H

#include "databaseinterface.h"

class SQLiteDatabaseConnection : public DatabaseInterface
{
public:
    SQLiteDatabaseConnection(const QString &fileName);
    bool connect(QString &error) override;

private:
    QString _dataBaseFile;
};

#endif // SQLITEDATABASECONNECTION_H
