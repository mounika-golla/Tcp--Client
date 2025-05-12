#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>

class TcpServer : public QObject {
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);

public slots:
    void listenToMessage();
    void onNewConnection();

private:
    QTcpServer *server;
};

#endif // TCPSERVER_H
