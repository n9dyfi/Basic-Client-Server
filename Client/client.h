#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QAbstractSocket>
#include <QtNetwork/QTcpSocket>
#include <QHostAddress>

class Client : public QObject
{
    Q_OBJECT
    QTcpSocket *socket;
    bool startingConversation;

public:
    explicit Client();

signals:

public slots:
    void receiveMessage();
    void connected();
    void errorOccured(QAbstractSocket::SocketError errorMsg);
};

#endif // CLIENT_H
