#include "mainwindow.h"
#include "appwindow.h"
#include "tcpclient.h"

#include <QGridLayout>
#include <QPushButton>
#include <QStringList>
#include <QIcon>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    QWidget *central = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    // App Grid
    QWidget *gridContainer = new QWidget(central);
    QGridLayout *layout = new QGridLayout(gridContainer);

    QStringList appNames = {
        "Settings", "Spotify", "Telegram", "WhatsApp"
    };

    QStringList iconPaths = {
        ":/new/prefix1/icons/settings(1).png",
        ":/new/prefix1/icons/spotify(1).png",
        ":/new/prefix1/icons/telegram(1).png",
        ":/new/prefix1/icons/whatsapp.jpeg"
    };

    for (int i = 0; i < appNames.size(); ++i) {
        QPushButton *button = new QPushButton();
        button->setMinimumSize(100, 120);
        button->setStyleSheet("QPushButton { border: none; }");

        QWidget *iconWidget = new QWidget(button);
        QVBoxLayout *vbox = new QVBoxLayout(iconWidget);
        vbox->setSpacing(5);
        vbox->setAlignment(Qt::AlignCenter);

        QLabel *iconLabel = new QLabel();
        QPixmap icon(iconPaths[i]);
        iconLabel->setPixmap(icon.scaled(64, 64));
        iconLabel->setFixedSize(80, 80);

        QLabel *textLabel = new QLabel(appNames[i]);
        textLabel->setAlignment(Qt::AlignCenter);

        vbox->addWidget(iconLabel);
        vbox->addWidget(textLabel);
        button->setLayout(vbox);

        layout->addWidget(button, i / 3, i % 3);

        connect(button, &QPushButton::clicked, this, [this, name = appNames[i]]() {
            openApp(name);
            TcpClient *client = new TcpClient(name, this);
            // You can still use signals from TcpClient if needed, but no logging display now
        });
    }

    mainLayout->addWidget(gridContainer);

    setCentralWidget(central);
    resize(600, 400);
    setWindowTitle("App Drawer - TCP Client");
}

void MainWindow::openApp(const QString &appName) {
    AppWindow *app = new AppWindow(nullptr, appName);
    app->setWindowTitle(appName);
    app->show();
}
