#ifndef APPLICATION_H
#define APPLICATION_H

#include "commandlineparser.h"
#include "configuration.h"

#include <memory>

class ConfigurationReader;

class Application
{
public:
    Application(const CommandLineParser &commandLineParser);
    int exec();

private:
    ConfigurationReader* createConfigReader(const CommandLineParser &commandLineParser);

private:
    std::shared_ptr<ConfigurationReader> _configReader;
    Configuration _config;
};

#endif // APPLICATION_H
