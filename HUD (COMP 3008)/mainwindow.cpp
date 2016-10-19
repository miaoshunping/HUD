#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "AudioComponent.h"
#include <QKeyEvent>
#include<iostream>
#include <QMovie>
#include <QSound>
#include <QThread>
#include <qsound.h>
#include <QMessageBox>
#include <QSoundEffect>
#include <QMediaPlayer>
#include<QTime>
void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(5);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}



    int counter = 1;
    int counter2= 1;
    int counter3= 1;
    int counter4=1 ;
    int counter5= 1;
    bool checkPlaying;
    bool hangingup;
    QMediaPlayer * player2 = new QMediaPlayer;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->label_3->setText("<font color='white'>Volume</font>");
    ui->label_3->setVisible(false);
    ui->label_2->setVisible(false);
    ui->progressBar->setVisible(false);
    ui->label_10->setVisible(false);

    ui->label->setAttribute(Qt::WA_TranslucentBackground);
    ui->label_2->setAttribute(Qt::WA_TranslucentBackground);
    ui->label_3->setAttribute(Qt::WA_TranslucentBackground);
    ui->label_4->setAttribute(Qt::WA_TranslucentBackground);
    ui->label_5->setAttribute(Qt::WA_TranslucentBackground);

    ui->label_7->setAttribute(Qt::WA_TranslucentBackground);
    ui->label_8->setAttribute(Qt::WA_TranslucentBackground);
    ui->label_9->setAttribute(Qt::WA_TranslucentBackground);
    ui->label_10->setAttribute(Qt::WA_TranslucentBackground);
    ui->label_11->setAttribute(Qt::WA_TranslucentBackground);





    static const QString sound3(":/coldplay.mp3");
    player2->setMedia(QUrl("qrc:/coldplay.mp3"));
    //player2->play();
    //checkPlaying =true;



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent * event)



{





// Implementing the volume increase feature via the A key in the Keyboard
    if(event->key() == Qt::Key_A){

        static const QString sound3(":/coldplay.mp3");

        // Setting the ui labels to be visible when A key is pressed
        ui->label_3->setVisible(true);
        ui->progressBar->setVisible(true);
        ui->progressBar->setValue(ui->progressBar->value()+1);

        player2->setVolume(player2->volume()+1);
        delay();

        // Setting the ui labels to be invisible when funtionality is done
        ui->label_3->setVisible(false);
        ui->progressBar->setVisible(false);



    };


// Implementing the volume decrease feature via the S key in the Keyboard

    if(event->key() == Qt::Key_S){


        // Setting the ui labels to be visible when S key is pressed
        ui->progressBar->setVisible(true);
        ui->label_3->setVisible(true);

        ui->progressBar->setValue(ui->progressBar->value()-1);
        player2->setVolume(player2->volume()-5);
        delay();

        // Setting the ui labels to be invisible when funtionality is done
        ui->progressBar->setVisible(false);
        ui->label_3->setVisible(false);




    };

//Simulating Phone Call
    if(event->key() == Qt::Key_D){
        ui->label->setVisible(true);
        ui->label_2->setVisible(true);

        ui->label_2->setText("<font color='white'>Call from Ray</font>");
        QMovie * movie = new QMovie(":/calling6.gif");


        player2->pause();

        ui->label->setMovie(movie);
        movie->start();
        ui->label_7->setVisible(false);

        counter5 = 1;

        static const QString sound(":/TELEPHONE.wav");
        static const QString sound3(":/raycalling1_converted.wav");
        QSound::play(sound);



        QSound::play(sound);
        QSound::play(sound3);





    };
//Implementing the Call Reject Feature with the F key on the keyboard
    if(event->key() == Qt::Key_F){


        if(counter5 == 1){


            QPixmap pixmap(":/hangup.png");
            ui->label->setVisible(false);
            ui->label_2->setVisible(false);

             ui->label_7->setVisible(true);
             ui->label_7->setPixmap(pixmap);

            counter5 = counter5 -1;

        }
        else{

         ui->label_7->setVisible(false);
            counter5 = counter5+1;


        }

        if((checkPlaying == true)){

         player2->play();

         }
    }


// Implementing The GPs functionality with G Key
    if(event->key()== Qt::Key_G){
        if (counter == 1){
            // Setting the ui labels to be visible when G key is pressed
            ui->label_4->setVisible(true);
            ui->label_5->setVisible(true);
            QPixmap pixmap(":/gps.png");
            ui->label_4->setPixmap(pixmap);
            ui->label_5->setText("<font color='white'>Left in 30 meters</font>");
            counter= counter -1;
        }
        else{
            ui->label_4->setVisible(false);
             ui->label_5->setVisible(false);
            counter = counter+1;
        }


    }

//Implementing the weather feature using the H key on the keyboard
    if(event->key()== Qt::Key_H){
    if(counter2 == 1){
        ui->label_8->setVisible(true);
        QPixmap pixmapa(":/weater.png");
        ui->label_8->setPixmap(pixmapa);
        counter2 = counter2 -1;

    }
    else{

        ui->label_8->setVisible(false);
        counter2 = counter2+1;
    }
    }


//Implementing the Message notification using the J key on the keyboard
    if(event->key()== Qt::Key_J){

        if(counter4 == 1){
             ui->label_9->setVisible(true);
             QPixmap pixmapa(":/message.png");
             ui->label_9->setPixmap(pixmapa);

            counter4 = counter4 -1;

         }
         else{

            ui->label_9->setVisible(false);
             counter4 = counter4+1;
        }
    }


//Implementing Play music feature using the L key on the keyboard
    if(event->key() == Qt::Key_L){

         ui->label_11->setVisible(true);
         QPixmap pixmapa(":/playbutton.png");
         ui->label_11->setPixmap(pixmapa);
         player2->play();
         checkPlaying = true;
         delay();
         ui->label_11->setVisible(false);
     }

//Implementing Pause music feature using the X key on the keyboard
    if(event->key() == Qt::Key_X){

        ui->label_11->setVisible(true);
        QPixmap pixmapa(":/pausebutton.png");
         ui->label_11->setPixmap(pixmapa);
         player2->pause();
         checkPlaying = false;
         delay();
         ui->label_11->setVisible(false);




    }

//Implementing the Rear view and Assisted Parking Feature using the Z key
    if(event->key() == Qt::Key_Z){

        if(counter3 == 1){
                ui->label->setVisible(false);
                ui->label_2->setVisible(false);
                ui->label_3->setVisible(false);
                ui->label_4->setVisible(false);
                ui->label_5->setVisible(false);

                ui->label_7->setVisible(false);
                ui->label_8->setVisible(false);
                ui->label_9->setVisible(false);

                ui->label_10->setVisible(true);
                ui->progressBar->setVisible(false);

                QPixmap pixmapaa(":/backmirror.png");
                ui->label_10->setPixmap(pixmapaa);
                counter3 = counter3 -1;

        }
        else{

            ui->label_10->setVisible(false);
            counter3 = counter3+1;
        }

    }



}
