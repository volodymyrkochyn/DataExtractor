#include "xmlconfigreader.h"
#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <QXmlStreamReader>

XmlConfigReader::XmlConfigReader(Configuration &config) :
    _config(config)
{
}

bool XmlConfigReader::readConfig(const QString &file)
{
    QFile f {file};
    if (!f.open(QIODevice::ReadOnly))
    {
        setError(QString("Can't open %1 file.").arg(file));
        return false;
    }

    QXmlStreamReader reader(&f);
    QDomDocument document;
    if (!document.setContent(reader.device()))
    {
        setError("Problem with parsing XML document.");
        return false;
    }

    auto databaseList = document.elementsByTagName("databasepath");
    for (int i = 0; i < databaseList.count(); ++i)
    {
        auto element = databaseList.at(i);
        _config.setDatabasePath(element.toElement().text());
    }

    auto tableList = document.elementsByTagName("tables");
    for (int i = 0; i < tableList.count(); ++i)
    {
        auto element = tableList.at(i);
        _config.setTables(element.toElement().text().split(", ").toVector());
    }
    return true;
}
