#include "sqlitedatabaseconnection.h"

#include <QFileInfo>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QDir>

SQLiteDatabaseConnection::SQLiteDatabaseConnection(const QString &fileName) :
    _dataBaseFile(fileName)
{
}

bool SQLiteDatabaseConnection::connect(QString &error)
{
    if (!QFileInfo(_dataBaseFile).exists())
    {
        error = QStringLiteral("Database file doesn't exists.");
        return false;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(_dataBaseFile);
    if (!db.open())
    {
        error = db.lastError().text();
        return false;
    }
    return true;
}
