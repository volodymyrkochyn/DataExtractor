#include "application.h"
#include "xmlconfigreader.h"
#include "dataextractorapp.h"
#include "sqlitedatabaseconnection.h"

Application::Application(const CommandLineParser &commandLineParser)
{
    _configReader.reset(createConfigReader(commandLineParser));
    if (_configReader)
    {
        bool ok = _configReader->readConfig(commandLineParser.configFile());
        if (!ok)
        {
            qWarning(_configReader->error().toLatin1());
            exit(-1);
        }
    }
}

/*!
 * \brief Application::exec - run all processes for extractig data from sqlite database and
 * \return 0 if success or -1 if it fails during process
 */
int Application::exec()
{
    qDebug("Extract data...");
    DataExtractor extract {_config,
                           std::make_shared<SQLiteDatabaseConnection>(_config.databasePath())};
    const bool ok  = extract.process();

    if (!ok)
    {
        qWarning(extract.lastError().toLatin1());
        return -1;
    }
    qDebug("Extracting data successfully finished.");
    return 0;
}

/*!
 * \brief Application::createConfigReader
 * Creates different config reader depends on parameters. Currently only XML config is available.
 */
ConfigurationReader *Application::createConfigReader(const CommandLineParser &commandLineParser)
{
    Q_UNUSED(commandLineParser)

    return new XmlConfigReader(_config);
}
