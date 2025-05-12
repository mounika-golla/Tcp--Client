#include "appwindow.h"

AppWindow::AppWindow(QWidget *parent, const QString &appName)
    : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    label = new QLabel("Opened " + appName);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);
    setLayout(layout);
    setWindowTitle(appName);
    resize(300, 150);
}
