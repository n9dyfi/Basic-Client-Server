#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QtNetwork/QTcpSocket>
#include <QTcpServer>

class Server : public QObject
{
Q_OBJECT

QTcpServer *tcpServer;
QTcpSocket *socket;

public:
explicit Server();

public slots:
void acceptConnection();
void receiveMessage();
};

#endif // SERVER_H
