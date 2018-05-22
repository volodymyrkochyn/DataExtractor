#include <QCoreApplication>
#include "commandlineparser.h"
#include "application.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CommandLineParser parser{QCoreApplication::arguments()};

    return Application(parser).exec();
}
