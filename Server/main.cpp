#include <QtCore/QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    new Server;

    return a.exec();
}
