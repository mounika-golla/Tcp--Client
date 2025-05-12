#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>

class TcpClient : public QObject {
    Q_OBJECT
public:
    explicit TcpClient(const QString &appName, QObject *parent = nullptr);

signals:
    void messageToGui(const QString &msg);

private slots:
    void onConnected();
    void onReadyRead();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError socketError);

private:
    QTcpSocket *socket;
    QString messageToSend;
};

#endif // TCPCLIENT_H
