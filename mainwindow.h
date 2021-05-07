#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"evenement.h"
#include <QTimer>

#include <QMediaPlayer>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
#include<QObject>

#include<QtCore>
#include<QtGui>



//#include <QSound>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class QMediaPlayer;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //QTimer *monTimer;


    QSqlDatabase myDB;
    void connClose()
    {
        myDB.close();
        myDB.removeDatabase("atelier5.db");

    }
    bool connOpen()
    {

        myDB =QSqlDatabase::addDatabase("QSLITE");
        myDB.setDatabaseName("atelier5.db");
        if (!myDB.open()){
            qDebug() <<"no connection to database";
            return false;

        } else {
            qDebug() <<"database connected";
            return true;
        }
    }



//private slots:


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

   void on_pushButton_17_clicked();

    void on_actionOpen_triggered();

    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();

    void on_pushButton_login_clicked();

    void on_open_clicked();

    void on_play_clicked();

    void on_pause_clicked();

    void on_stop_clicked();

    void on_mute_clicked();

    void on_volume_valueChanged(int value);



    void on_pushButton_imprimer_clicked();

    void on_web_clicked();

    void on_actioncopier_triggered();

    void on_actionouvrir_triggered();

    void on_actionnouveau_triggered();

    void on_actioncoller_triggered();

    void on_actioncouper_triggered();

    void on_actionrefaire_triggered();

    void on_actionannuler_triggered();

    void on_actionenregistrer_triggered();

    void on_actionenregistrer_sous_triggered();

    void on_pushButton_excel_clicked();

public slots :

    //void finTempo();
    void myfunction();

private:
    Ui::MainWindow *ui;
QTimer *timer;
   // QSound *son;

 QMediaPlayer *mMediaPlayer;

/*QMediaPlayer *player ;
QVideoWidget* vw;
QProgressBar* bar;
QSlider* slider;
*/

//notepad

QString mFilename;

};
#endif // MAINWINDOW_H
