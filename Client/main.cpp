#include <QtCore/QCoreApplication>
#include "client.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    new Client;

    return a.exec();
}
