#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QIntValidator>
#include "participants.h"
#include"evenements.h"
#include <QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>

#include<QDialog>
#include<QFileInfo>
#include<QFileDialog>

#include<QTextDocument>

#include<QDebug>
#include <QDateTime>

//#include<QMediaPlayer>
//#include<QvideoWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


     ui->setupUi(this);
/*
    mMediaPlayer = new QMediaPlayer(this);

    connect(mMediaPlayer, &QMediaPlayer::positionChanged, [&](qint64 pos) {
        ui->avance->setValue(pos);
    });

    connect(mMediaPlayer, &QMediaPlayer::durationChanged, [&](quint64 dur){
        ui->avance->setMaximum(dur);
                               });


   player = new QMediaPlayer(this);
   // vw = new QVideoWidget(this);
    player->setVideoOutput(vw);
    //this->setCentralWidget(vw);


 slider =new QSlider(this);
 bar = new QProgressBar(this);

 slider->setOrientation(Qt::Horizontal);
 ui->statusbar->addPermanentWidget(slider);
 ui->statusbar->addPermanentWidget(bar);

 connect(player, &QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
 connect(player, &QMediaPlayer::positionChanged,slider,&QSlider::setValue);

 connect(slider, &QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

 connect(player, &QMediaPlayer::durationChanged,bar,&QProgressBar::setMaximum);
 connect(player, &QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);





   /* QMediaPlayer* player= new QMediaPlayer;
    QVideoWidget* vw = new QVideoWidget;

    player->setVideoOutput(vw);
    player->setMedia(QUrl::fromLocalFile("C:/Users/User/OneDrive/Documents/atelier5/images"));

    vw->setGeometry(100,100,300,400);
    vw->show();

    player->play();

    qDebug() <<player->state();

*/



    timer=new QTimer(this);

        connect(timer, SIGNAL(timeout()), this,SLOT(myfunction()));
timer->start(5000);


     //son=new QSound(":/sons/bubble.wav");
  // QPixmap pix("C:/Users/User/Downloads/login.png");
   //ui->label_pic->setPixmap();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_actionSon_triggered()

    {

      son->play();

    }*/

/*Widget::~Widget()
{
    delete ui;
}
*/

void MainWindow::on_pushButton_clicked()
{

    participants p;
      int id=ui->lineEdit_ID->text().toInt();
      int age=ui->lineEdit_AGE->text().toInt();
      QString nom=ui->lineEdit_NOM->text();
      QString prenom=ui->lineEdit_PRENOM->text();
      QString adresse=ui->lineEdit_DEP->text();

  participants E(nom,prenom,adresse,id,age);
  bool test=E.ajouter();
  if(test)
  {
      ui->tableView->setModel(p.afficher());
      QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectue \n click cancel to exit."), QMessageBox::Cancel);
  }

  ui->stackedWidget->setCurrentIndex(1);


}

void MainWindow::on_pushButton_2_clicked()
{
    participants p;
    ui->tableView->setModel(p.afficher());
}

void MainWindow::on_pushButton_3_clicked()
{
    participants p;
           int id = ui->lineEdit_ID_2->text().toInt();
           int age= ui->lineEdit_AGE_2->text().toInt();
           QString nom = ui->lineEdit_NOM_2->text();
           QString prenom = ui->lineEdit_PRENOM_2->text();
           QString adresse= ui->lineEdit_DEP_2->text();


           participants  (nom,prenom,adresse,id,age) ;
           bool test =p.modifier(id,age,nom,prenom,adresse);
           if(test)
           {ui->tableView->setModel(p.afficher());
               QMessageBox::information(nullptr, QObject::tr("modifier un employe"),
                                        QObject::tr("employe  modifié.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);}
           else
               QMessageBox::critical(nullptr, QObject::tr("Modifier un employe"),
                                     QObject::tr("Erreur !.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_4_clicked()
{

    participants Etmp;
        Etmp.setId(ui->lineEdit_supprimer->text().toInt());
        QMessageBox msgbox;
            msgbox.setWindowTitle("supprimer");
            msgbox.setText("voulez_vous supprimer cette réclamation?");
            msgbox.setStandardButtons(QMessageBox ::Yes);
            msgbox.addButton(QMessageBox::No);
            if(msgbox.exec()==QMessageBox::Yes)
            {
      bool test=Etmp.supprimer(Etmp.getId());
      QMessageBox msgBox;

      if(test)
      {

          QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("suppression effectuée \n click cancel to exit."), QMessageBox::Cancel);
          {ui->tableView->setModel(Etmp.afficher());}

      }
      else
          QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("suppression non effectuer.\n click cancel to exis."), QMessageBox::Cancel);
      msgBox.exec();

    }

}

void MainWindow::on_pushButton_7_clicked()
{
    evenement e;
      int id=ui->lineEdit_IDEV->text().toInt();
      int capacite=ui->lineEdit_CAP->text().toInt();
      QString nom=ui->lineEdit_NOMEV->text();
      QString adresse=ui->lineEdit_adrev->text();
      QDate date_debut=ui->dateEdit->date();
      QDate date_fin=ui->dateEdit_2->date();

  evenement E(nom,adresse,capacite,id,date_debut, date_fin);
  bool test=E.ajouter();
  if(test)
  {
     // ui->tableView->setModel(e.afficher());
      QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectue \n click cancel to exit."), QMessageBox::Cancel);
  }
}



void MainWindow::on_pushButton_8_clicked()
{
    evenement e;
    int id=ui->lineEdit_MOD_ID->text().toInt();
    int capacite=ui->lineEdit_MOD_CAP->text().toInt();
    QString nom=ui->lineEdit_MOD_NOM->text();
    QString adresse=ui->lineEdit_MOD_ADD->text();
    QDate date_debut=ui->dateEdit_MOD_DEB->date();
    QDate date_fin=ui->dateEdit_MOD_FIN->date();

           evenement  (nom,adresse,capacite,id,date_debut, date_fin) ;
           bool test =e.modifier(id,nom,date_debut, date_fin,adresse,capacite);
           if(test)
           {ui->tableView_2->setModel(e.afficher());
               QMessageBox::information(nullptr, QObject::tr("modifier un evenement"),
                                        QObject::tr("evenement  modifié.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);}
           else
               QMessageBox::critical(nullptr, QObject::tr("Modifier un evenement"),
                                     QObject::tr("Erreur !.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_9_clicked()
{
    evenement e;
    ui->tableView_2->setModel(e.afficher());
}



void MainWindow::on_pushButton_10_clicked()
{
    evenement e;
        e.setId(ui->lineEdit_supp_2->text().toInt());
        QMessageBox msgbox;
            msgbox.setWindowTitle("supprimer");
            msgbox.setText("voulez_vous supprimer cette réclamation?");
            msgbox.setStandardButtons(QMessageBox ::Yes);
            msgbox.addButton(QMessageBox::No);
            if(msgbox.exec()==QMessageBox::Yes)
            {
      bool test=e.supprimer(e.getId());
      QMessageBox msgBox;

      if(test)
      {

          QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("suppression effectuée \n click cancel to exit."), QMessageBox::Cancel);
          {ui->tableView_2->setModel(e.afficher());}

      }
      else
          QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("suppression non effectuer.\n click cancel to exis."), QMessageBox::Cancel);
      msgBox.exec();

    }

}

/*void MainWindow::on_pushButton_11_clicked()
{

    participants p;
    ui->label_25->setNum(((p.stati1())*100/p.nb_total()));
    ui->label_26->setNum(((p.stati())*100/p.nb_total()));

}
*/

void MainWindow::on_pushButton_12_clicked()
{
    QDialog QFileDialog;
        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("reclamation.pdf"); }

                QPrinter printer(QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                /*QPrinter printer;*/
                ui->tableView_2->render(&printer);




                QTextDocument doc;
                QSqlQuery q;
                q.prepare("SELECT * FROM reclamation ");
                q.exec();
                QString pdf="<br> <img src='D:/Esprit/2A2/projet c++/logo/debug2.png' height='42' width='144'/> <h1  style='color:red'>LISTE DES RECLAMATION  <br></h1>\n <br> <table>  <tr>  <th> CODE </th> <th> SUJET </th> <th> COMMENTAIRE </th> <th> DATE AJOUT </th>  </tr>" ;


                while ( q.next()) {

                    pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>   <td>   " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>    <td>"+q.value(4).toString()+" </td>" ;

                }
                doc.setHtml(pdf);
                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
             /*   doc.print(&printer);*/
                ui->tableView_2->render(&printer);
}

void MainWindow::on_pushButton_5_clicked()
{
   ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_13_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_15_clicked()
{
    participants e;
       //QString critere=ui->cb_historique->currentText();
           QString mode;
            if (ui->rb_asc_historique->isChecked()==true)
       {
                ui->tableView->setModel(e.trie());


       }
            else if(ui->aa->isChecked()==true)

                ui->tableView->setModel(e.trie2());
}

void MainWindow::on_pushButton_16_clicked()
{

    participants e;
    QString text;
    if (ui->radioButton_ID->isChecked()==true)
{
text=ui->line_recherche_critere->text();
     if(text == "")

     {

         ui->tableView->setModel(e.afficher());

     }

     else

     {



         ui->tableView->setModel(e.chercher_emp(text));

     }
    }
     if(ui->radioButton_age->isChecked()==true)
    {
        text=ui->line_recherche_critere->text();
             if(text == "")

             {

                 ui->tableView->setModel(e.afficher());

             }

             else

             {



                 ui->tableView->setModel(e.chercher_emp1(text));

             }

    }
     else if     (ui->radioButton_nom->isChecked()==true)
     {

         text=ui->line_recherche_critere->text();
              if(text == "")

              {

                  ui->tableView->setModel(e.afficher());

              }

              else

              {



                  ui->tableView->setModel(e.chercher_emp2(text));

              }
     }
}

/*void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
*/

/*void MainWindow::finTempo()

{

    qDebug() <<"update..";

    //monTimer->setSingleShot(true); //active le mode singleShot
             //monTimer->start(15000); //démarre une tempo de 15 secondes

}*/

/*void MainWindow::myfunction()
{
    QTime time =QTime::currentTime();
    QString time_text =time.toString("hh : mm : ss");
    if ((time.second()%2 ==0 ))
    {
        time_text[3]=' ';
        time_text[3]=' ';
    }
    ui->label_date_time->setText(time_text);
}

*/

/*
void MainWindow::on_actionOpen_triggered()
{
    QString filename=QFileDialog::getOpenFileName(this,"Open a file","","video File (*.avi, *.mpg, *.mp4)" );
    on_actionOpen_triggered();

    player->setMedia(QUrl::fromLocalFile(filename));

    on_actionPlay_triggered();
}

void MainWindow::on_actionPlay_triggered()
{
     player->play();
     ui->statusbar->showMessage("playing");
}

void MainWindow::on_actionPause_triggered()
{
    player->pause();
    ui->statusbar->showMessage("paused...");
}

void MainWindow::on_actionStop_triggered()
{
    player->stop();
    ui->statusbar->showMessage("stopped");
}
*/
void MainWindow::on_pushButton_login_clicked()
{
    QString username= ui->lineEdit_username->text();
    QString password= ui->lineEdit_password->text();

    if (username == "projetqt" && password== "test") {
        QMessageBox::information(this, "Login", "Username and Pasword is not correct ");
    }
        else { QMessageBox::warning(this, "Login", "Username and Pasword is not correct ");
            {
        }
    }
}


/*void MainWindow::on_open_clicked()
{
   QString filename= QFileDialog::getOpenFileName(this, "open");
    if (filename.isEmpty()){
        return;
    }
    mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
            mMediaPlayer->setVolume(ui->volume->value());
    on_play_clicked();
}

void MainWindow::on_play_clicked()
{
    mMediaPlayer->play();
}

void MainWindow::on_pause_clicked()
{
    mMediaPlayer->pause();
}

void MainWindow::on_stop_clicked()
{
    mMediaPlayer->stop();
}

void MainWindow::on_mute_clicked()
{
    if (ui->mute->text() == "Mute")
    { mMediaPlayer->setMuted(true);
        ui->mute->setText("Unmute");}
    else { mMediaPlayer->setMuted(false);
        ui->mute->setText("Mute");
    }
    mMediaPlayer->setMuted(true);
}

void MainWindow::on_volume_valueChanged(int value)
{

 mMediaPlayer->setVolume(value);
}
*/
