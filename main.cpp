#include <QCoreApplication>
#include "commandlineparser.h"
#include "dataextractorapp.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CommandLineParser parser{QCoreApplication::arguments()};
    DataExtractorApp app{parser};
    app.exec();

    return a.exec();
}
