#ifndef XMLCONFIGREADER_H
#define XMLCONFIGREADER_H

#include "configurationreader.h"
#include "configuration.h"

/*!
 * \brief The XmlConfigReader class implements read configuration file in XML format.
 * config tamplate:
 *
 * <?xml version="1.0" encoding="UTF-8"?>
<config>
    <common>
        <databasepath>some_file.db</databasepath>
    </common>
    <tables>
        <table name="name_of_table">column1,column2,columnN</table>
    </tables>
</config>
 */
class XmlConfigReader : public ConfigurationReader
{
public:
    XmlConfigReader(Configuration &config);
    bool readConfig(const QString &file) override;

private:
    Configuration &_config;
};

#endif // XMLCONFIGREADER_H
