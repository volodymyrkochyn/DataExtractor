#include "dataextractorapp.h"
#include <QDebug>

DataExtractorApp::DataExtractorApp(const CommandLineParser &parser)
{
    _config = parser.configFile();
}

void DataExtractorApp::exec()
{
    qDebug("Execute data extracting...");
    qDebug("Config:");
    qDebug() << _config;

    exit(0);
}
