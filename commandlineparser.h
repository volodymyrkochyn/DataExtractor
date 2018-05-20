#ifndef COMMANDLINEPARSER_H
#define COMMANDLINEPARSER_H

#include <QCommandLineParser>

class CommandLineParser
{
public:
    CommandLineParser(const QStringList &arguments);
    QString configFile() const { return _config; }

private:
    QCommandLineParser _parser;
    QString _config;
};

#endif // COMMANDLINEPARSER_H
