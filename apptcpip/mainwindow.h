#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class TcpClient;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void openApp(const QString &appName);
};

#endif // MAINWINDOW_H
