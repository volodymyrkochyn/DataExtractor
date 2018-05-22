#ifndef DATABASEINTERFACE_H
#define DATABASEINTERFACE_H

#include <QString>
/*!
 * \brief The DatabaseInterface class provide interface of connection to any type of
 * database.
 */

class DatabaseInterface
{
public:
    virtual ~DatabaseInterface() =default;
    /*!
     * \brief connect implement this method to establish connection to database.
     * \param error - message about problem that occurs.
     * \return true in case connection was established.
     */
    virtual bool connect(QString &error) =0;
};

#endif // DATABASEINTERFACE_H
