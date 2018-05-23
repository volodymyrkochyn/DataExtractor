#include "commandlineparser.h"

CommandLineParser::CommandLineParser(const QStringList &arguments)
{
    _parser.addPositionalArgument("[ config file ]", "Set configuration file in xml format");
    _parser.setApplicationDescription("Use this utility to extract data from SQLite database.");
    _parser.addHelpOption();

    _parser.process(arguments);

    auto args = _parser.positionalArguments();
    if (!args.isEmpty())
    {
        // first arg must be config file
        _config = args.first();
    }
    else
    {
        qWarning("Please specify config file.");
        ::exit(-1);
    }
}
