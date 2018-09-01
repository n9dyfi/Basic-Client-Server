#include <QDateTime>
#include "client.h"

Client::Client()
{
    socket = new QTcpSocket();
    socket->connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    socket->connect(socket,SIGNAL(readyRead()),this,SLOT(receiveMessage()));
    socket->connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),
                    this,SLOT(errorOccured(QAbstractSocket::SocketError)));

    qDebug() << "- client running, connecting to the server.";

    socket->connectToHost(QHostAddress::LocalHost,1025);
    startingConversation = true;
}

void Client::receiveMessage()
{
    qDebug() << "- message received from server.";
    QByteArray message = socket->readLine();
    qDebug() << message.constData();

    if(startingConversation)
    {
        qDebug() << "- reply to server.";
        message = QString("Hello, server!").toLocal8Bit().constData();
        socket->write(message);
        startingConversation=false;
    }

}


void Client::connected()
{
    qDebug() << "- connection successful.";
}

void Client::errorOccured(QAbstractSocket::SocketError errorMsg)
{
    if(errorMsg==QAbstractSocket::RemoteHostClosedError)
    {
        qDebug() << "- server closed the connection, exiting...";
        exit(EXIT_SUCCESS);
    }
    else
        qDebug() << "Error: " << errorMsg;
}
