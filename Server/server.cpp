#include "server.h"

Server::Server()
{
tcpServer = new QTcpServer();

if(tcpServer->listen(QHostAddress::LocalHost,1025))
{
qDebug() << "- server up.";
qDebug() << "- address: " << tcpServer->serverAddress();
qDebug() << "- port: " << tcpServer->serverPort();
QObject::connect(tcpServer,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
}
else
{
qDebug() << "Failed to start the server:" << tcpServer->serverError();
exit(EXIT_FAILURE);
}
}

void Server::acceptConnection()
{
qDebug() << "- accept client connection.";

socket = tcpServer->nextPendingConnection();
connect(socket,SIGNAL(disconnected()), socket, SLOT(deleteLater()));
connect(socket, SIGNAL(readyRead()), this, SLOT(receiveMessage()));

qDebug() << "- greet the client.";
QByteArray message = QString("Hello, client!").toLocal8Bit().constData();
socket->write(message);
}

void Server::receiveMessage()
{

QByteArray message = socket->readLine();
qDebug() << "- message received from client.";
qDebug() << message.constData();

// Acknowledge
message = QString("Thanks for the message, goodbye!").toLocal8Bit().constData();
socket->write(message);
socket->disconnectFromHost();

}
