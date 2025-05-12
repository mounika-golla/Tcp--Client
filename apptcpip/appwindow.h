#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QVBoxLayout>

class AppWindow : public QWidget {
    Q_OBJECT

public:
    explicit AppWindow(QWidget *parent = nullptr, const QString &appName = "");

private:
    QLabel *label;
};

#endif // APPWINDOW_H
