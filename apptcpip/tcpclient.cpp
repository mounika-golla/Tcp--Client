#include "tcpclient.h"

TcpClient::TcpClient(const QString &appName, QObject *parent)
    : QObject(parent), messageToSend("Opening " + appName) {

    socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::connected, this, &TcpClient::onConnected);
    connect(socket, &QTcpSocket::readyRead, this, &TcpClient::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &TcpClient::onDisconnected);
    connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::errorOccurred),
            this, &TcpClient::onError);

    socket->connectToHost("127.0.0.1", 1234);
}

void TcpClient::onConnected() {
    emit messageToGui("Connected to server.");
    socket->write(messageToSend.toUtf8());
}

void TcpClient::onReadyRead() {
    QByteArray data = socket->readAll();
    emit messageToGui("Received from server: " + QString(data));
}

void TcpClient::onDisconnected() {
    emit messageToGui("Disconnected from server.");
}

void TcpClient::onError(QAbstractSocket::SocketError socketError) {
    Q_UNUSED(socketError);
    emit messageToGui("Socket error: " + socket->errorString());
}
