#ifndef CONFIGURATIONREADER_H
#define CONFIGURATIONREADER_H

#include <QString>

/*!
 * \brief The ConfigurationReader class provide interface for reading config file
 */
class ConfigurationReader
{
public:
    ConfigurationReader();
    virtual ~ConfigurationReader() {}

    /*!
     * \brief readConfig read configuration from \a file and return true if operation was
     * success.
     */
    virtual bool readConfig(const QString &file) =0;

    /*!
     * \brief error return text of error if it occurs during reading config.
     */
    QString error() const { return _error; }

protected:
    void setError(const QString &error);

private:
    QString _error;
};

#endif // CONFIGURATIONREADER_H
