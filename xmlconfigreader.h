#ifndef XMLCONFIGREADER_H
#define XMLCONFIGREADER_H

#include "configurationreader.h"
#include "configuration.h"

class XmlConfigReader : public ConfigurationReader
{
public:
    XmlConfigReader(Configuration &config);
    bool readConfig(const QString &file) override;

private:
    Configuration &_config;
};

#endif // XMLCONFIGREADER_H
