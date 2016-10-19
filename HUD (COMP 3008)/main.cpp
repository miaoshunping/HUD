#include "mainwindow.h"
#include <QApplication>
#include <QMediaPlayer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setStyleSheet("background-image : url(:/oo2.jpg);"
                    "background-repeat: no-repeat;");

   // QMediaPlayer * player2 = new QMediaPlayer;
    //static const QString sound3(":/coldplay.mp3");
    //player2->setMedia(QUrl("qrc:/coldplay.mp3"));
    //player2->setVolume(50);
    //player2->play();


    w.show();

    return a.exec();
}
