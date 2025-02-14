#include "mainwindow.cpp"
#include "database.cpp"
#include "view.cpp"
#include "player.cpp"
#include "cheat.cpp"
#include "role.h"
#include "keys.h"
#include "tools.h"
#include "monster.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QStandardPaths>
#include <QDir>
// Declare global varible
DataBase db;
Player player;
Monster monsters[13];
Tools tools;
Keys keys;
int map[14][14][10];
int mode = 1;

// Main function
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Add BGM
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/welcome.wav"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    QMediaPlayer *bgm = new QMediaPlayer();
    bgm->setPlaylist(playlist);
    bgm->play();

    // Connect database
    QString path = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/magictower";
    QDir dir(path);
    if (!dir.exists()) {
        dir.mkdir(path);
    }
    db.Connect(path  + "/magictowerdb.sqlite");

    // Main window
    MainWindow w;
    w.show();
    return a.exec();
}
