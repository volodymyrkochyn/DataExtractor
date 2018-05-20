#ifndef DATAEXTRACTORAPP_H
#define DATAEXTRACTORAPP_H

#include "commandlineparser.h"

class DataExtractorApp
{
public:
    DataExtractorApp(const CommandLineParser &parser);
    void exec();

private:
    QString _config;
};

#endif // DATAEXTRACTORAPP_H
