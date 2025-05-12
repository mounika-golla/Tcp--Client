#include "tcpserver.h"
#include <QTcpSocket>
#include <QDebug>

TcpServer::TcpServer(QObject *parent) : QObject(parent), server(nullptr) {}

void TcpServer::listenToMessage() {
    qDebug() << "Message Receiver Socket created!!";

    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &TcpServer::onNewConnection);

    if (!server->listen(QHostAddress::Any, 1234)) {
        qDebug() << "Server failed to bind:" << server->errorString();
        return;
    }

    qDebug() << "Message Receiver Socket bind!!";
    qDebug() << "Message Receiver Socket listening!!";
}

void TcpServer::onNewConnection() {
    QTcpSocket *socket = server->nextPendingConnection();

    QString message;
    message += "Message Receiver Socket created!!\n";
    message += "Message Receiver Socket bind!!\n";
    message += "Message Receiver Socket listening!!\n";

    socket->write(message.toUtf8());
    socket->flush();

    connect(socket, &QTcpSocket::readyRead, [socket]() {
        QByteArray data = socket->readAll();
        QString received = QString::fromUtf8(data);
        qDebug() << "Received message from client:" << received;
    });

    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
}
