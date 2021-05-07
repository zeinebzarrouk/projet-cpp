#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
//#include "historique.h"
#include"QPdfWriter"
#include"QtPrintSupport/QPrinter"
#include"QPainter"
#include <QPrintDialog>
#include <QTextDocument>
#include "smtp.h"
#include <QtWidgets>
#include <QPrinter>
#include <QPixmap>
#include <QSound>
#include <QDateTime>
#include <QtMultimedia/QMediaPlayer>
//#include"stati.h"
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QPrinter>
#include <QPrintDialog>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QTimer>
//#include"QSortFilterProxyModel"
/*MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}*/

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
  ,  ui(new Ui::MainWindow)
{
   ui->setupUi(this);

refresh_mortadha();
//smartTools.connect_arduino();

//connect(smartTools.getserial(), SIGNAL(readyRead()), this, SLOT(readTemp()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::refresh_mortadha(){
    ui->Publicite_affichage_2->setModel(tmp_publicite.afficher());
    ui->afficher_promo->setModel(tmp_promotion.afficher());

}


QString MainWindow::ConvertirTime(){
    QTime duree =ui->lineEdit_datec_2->time();
    QString h1=QString((duree.toString()[0]));
    QString h2=QString((duree.toString()[1]));
    QString m1=QString((duree.toString()[3]));
    QString m2=QString((duree.toString()[4]));
    QString heure=h1.append(h2);
    heure=heure.append(":");
    heure=heure.append(m1);
    heure=heure.append(m2);
    return heure;
}





void MainWindow::on_Publicite_affichage_activated(const QModelIndex &index)
{
    QString id=ui->Publicite_affichage_2->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM PUBLICITE WHERE ID='"+id+"'");
    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_id1->setText(query.value(0).toString());
            ui->lineEdit_nom1->setText(query.value(1).toString());
            ui->lineEdit_prix1->setText(query.value(2).toString());
            ui->lineEdit_duree1_2->setText(query.value(3).toString());
            ui->lineEdit_idp1->setText(query.value(4).toString());


        }

    }
    else
    {
        QObject::tr("Veuillez Choisir Un ID Du Tableau SVP");
    }
}
//Fin Crud Publicite



//Crud Promotion





void MainWindow::on_Promotion_affichage_activated(const QModelIndex &index)
{
    QString id=ui->afficher_promo->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM PROMOTION WHERE ID='"+id+"'");
    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_id_pr_2->setText(query.value(0).toString());
            ui->lineEdit_nom_pr_2->setText(query.value(1).toString());
            ui->lineEdit_pourc_2->setText(query.value(2).toString());
            ui->lineEdit_idp_pr_2->setText(query.value(4).toString());


        }

    }
    else
    {
        QObject::tr("Veuillez Choisir Un ID Du Tableau SVP");
    }

}


//Fin Crud Promotion




void MainWindow::on_recherche_Publicite_textChanged()
{
    if(ui->recherche_Publicite_2->text()!="")
    {        //QString b=ui->comboBox_recherche_Publicite_2->currentText();
        QString a=ui->recherche_Publicite_2->text();
        ui->Publicite_affichage_2->setModel(tmp_publicite.displayClause("WHERE (ID LIKE '%"+a+"%' OR NOM LIKE '%"+a+"%' OR PRIX LIKE '%"+a+"%' OR DUREE LIKE '%"+a+"%' OR ID_P LIKE '%"+a+"%') "));
    }
    else
        ui->Publicite_affichage_2->setModel(tmp_publicite.afficher());

}




void MainWindow::on_tri_croissant_publicite_clicked()
{
    ui->Publicite_affichage_2->setModel(tmp_publicite.tricroissant());

}

void MainWindow::on_tri_deccroissant_publicite_clicked()
{
    ui->Publicite_affichage_2->setModel(tmp_publicite.trideccroissant());

}


void MainWindow::on_pdf_publicite_clicked()
{
    QPdfWriter pdf("C:/PdfPublicite.pdf");
    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(2300,1200,"Liste Des Publicite");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 50));
    // painter.drawText(1100,2000,afficheDC);
    painter.drawRect(1500,200,7300,2600);
    //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
    painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(300,3300,"ID");
    painter.drawText(2300,3300,"NOM");
    painter.drawText(4300,3300,"PRIX");
    painter.drawText(6300,3300,"DUREE");
    painter.drawText(8000,3300,"IDP");



    QSqlQuery query;
    query.prepare("select * from PUBLICITE");
    query.exec();
    while (query.next())
    {
        painter.drawText(300,i,query.value(0).toString());
        painter.drawText(2300,i,query.value(1).toString());
        painter.drawText(4300,i,query.value(2).toString());
        painter.drawText(6300,i,query.value(3).toString());
        painter.drawText(8000,i,query.value(4).toString());



        i = i +500;
    }
    int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Admin/Desktop/PdfPublicite.pdf"));

        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}




/*void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        N.mail_Publicite();
}

void MainWindow::on_send_mail_mortadha_clicked()
{

    Smtp* smtp = new Smtp("youssefksouri1122@gmail.com","youssefksouri01","smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    smtp->sendMail("youssefksouri1122@gmail.com","bouzgarrou.mortadha2000@gmail.com",ui->subject->text(),ui->msg->toPlainText());
}


*/





/*
void MainWindow::on_stat_promotion_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from PROMOTION where POURCENTAGE < 10 ");
    float salaire=model->rowCount();
    model->setQuery("select * from PROMOTION where POURCENTAGE  between 10 and 50 ");
    float salairee=model->rowCount();
    model->setQuery("select * from PROMOTION where POURCENTAGE>50 ");
    float salaireee=model->rowCount();
    float total=salaire+salairee+salaireee;
    QString a=QString("moins de 10% "+QString::number((salaire*100)/total,'f',2)+"%" );
    QString b=QString("entre 10% et 50%  "+QString::number((salairee*100)/total,'f',2)+"%" );
    QString c=QString("+50%"+QString::number((salaireee*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,salaire);
    series->append(b,salairee);
    series->append(c,salaireee);
    if (salaire!=0)
    {QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());}
    if ( salairee!=0)
    {
        // Add label, explode and define brush for 2nd slice
        QPieSlice *slice1 = series->slices().at(1);
        //slice1->setExploded();
        slice1->setLabelVisible();
    }
    if(salaireee!=0)
    {
        // Add labels to rest of slices
        QPieSlice *slice2 = series->slices().at(2);
        //slice1->setExploded();
        slice2->setLabelVisible();
    }
    // Create the chart widget
    QChart *chart = new QChart();
    // Add data to chart with title and hide legend
    chart->addSeries(series);
    chart->setTitle("Pourcentage Par Pourcentage de promotion :Nombre Des Promotions "+ QString::number(total));
    chart->legend()->hide();
    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();
}*/
/*
void MainWindow::on_stat_publicite_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from PUBLICITE where PRIX < 100 ");
    float salaire=model->rowCount();
    model->setQuery("select * from PUBLICITE where PRIX  between 100 and 500 ");
    float salairee=model->rowCount();
    model->setQuery("select * from PUBLICITE where PRIX>500 ");
    float salaireee=model->rowCount();
    float total=salaire+salairee+salaireee;
    QString a=QString("moins de 100 Dinars "+QString::number((salaire*100)/total,'f',2)+"%" );
    QString b=QString("entre 100 et 500 Dinars "+QString::number((salairee*100)/total,'f',2)+"%" );
    QString c=QString("+500 Dinars "+QString::number((salaireee*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,salaire);
    series->append(b,salairee);
    series->append(c,salaireee);
    if (salaire!=0)
    {QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());}
    if ( salairee!=0)
    {
        // Add label, explode and define brush for 2nd slice
        QPieSlice *slice1 = series->slices().at(1);
        //slice1->setExploded();
        slice1->setLabelVisible();
    }
    if(salaireee!=0)
    {
        // Add labels to rest of slices
        QPieSlice *slice2 = series->slices().at(2);
        //slice1->setExploded();
        slice2->setLabelVisible();
    }
    // Create the chart widget
    QChart *chart = new QChart();
    // Add data to chart with title and hide legend
    chart->addSeries(series);
    chart->setTitle("Pourcentage Par Prix :Nombre Des PUBLICITE "+ QString::number(total));
    chart->legend()->hide();
    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();
}*/
/*
void MainWindow::on_tri_croissant_promotion_mortadha_2_clicked()
{
 ui->afficher_promo->setModel(tmp_promotion.tricroissant());
}*/





/*
void MainWindow::on_pb_ajouter_mortadha_2_clicked()//ajouter publi
{
    int id = ui->lineEdit_id_3->text().toInt();
    QString nom= ui->lineEdit_nom_3->text();
    int prix= ui->lineEdit_prix_3->text().toInt();
    QString duree=ConvertirTime();
    QString id_p= ui->lineEdit_idp_3->text();
    Publicite e(id,nom,prix,duree,id_p);



    if (ui->lineEdit_id_3->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP IDENTIFIANT!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }

    else if (ui->lineEdit_nom_3->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP nom!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_prix_3->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP prix!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_idp_3->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP id produit!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else{

        bool test=e.ajouter();
        if(test)
        {

            refresh_mortadha();
            N.notification_ajoutPublicite();
            musicAdd->setMedia(QUrl("C:/sound/ajout succe.mp3"));

             musicAdd->play();

            QMessageBox::information(0, qApp->tr("Ajout"),

                                     qApp->tr("Publicite ajoutée"), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter une Publicite"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }

}
*/
void MainWindow::on_pushButton_7_clicked()
{
    QString id = ui->lineEdit_id_pr_2->text();
    QString nom= ui->lineEdit_nom_pr_2->text();
    int pourc= ui->lineEdit_pourc_2->text().toInt();
    QDate datee =ui->dateEdit->date();
    QString id_p= ui->lineEdit_idp_pr_2->text();
    Promotion p(id,nom,pourc,datee,id_p);

    if (ui->lineEdit_id_pr_2->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP IDENTIFIANT!!!!") ;

        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);


    }

    else if (ui->lineEdit_nom_pr_2->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP Nom!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_idp_pr_2->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP ID PRODUIT!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }

    else if ((p.test_pourc(pourc)==false)||(ui->lineEdit_pourc_2->text().isEmpty()))
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP Pourcentage!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }






    else{
        bool test=p.ajouter();
        if(test)
        {

            refresh_mortadha();
            musicAdd->setMedia(QUrl("C:/sound/ajout succe.mp3"));

             musicAdd->play();
            N.notification_ajoutPromotion();

            QMessageBox::information(nullptr, QObject::tr("Ajouter une Promotion"),
                                     QObject::tr("Promotion ajoutée.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter une Promotion"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void MainWindow::on_pushButton_24_clicked()
{
    int id=ui->lineEdit_id1->text().toInt();
    int prix = ui->lineEdit_prix1->text().toInt();
    QString nom = ui->lineEdit_nom1->text();
    QString duree = ui->lineEdit_duree1_2->text();
    QString id_p= ui->lineEdit_idp1->text();
    Publicite pub (id,nom,prix,duree,id_p);



    if (ui->lineEdit_id1->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP IDENTIFIANT!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }

    else if (ui->lineEdit_nom1->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP nom!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_prix1->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP prix!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_idp1->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP id produit!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_duree1_2->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP DUREE!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }

    else{

      bool test=pub.modifier();
        if(test)
        {
            //QMessageBox::information(this," Modifier "," Votre Publicite est modifiée") ;
            QMessageBox::information(0, qApp->tr("Modification"),

                                     qApp->tr("Publicite Modifiée"), QMessageBox::Cancel);


            N.notification_modifierPublicite();
            musicAdd->setMedia(QUrl("C:/sound/modif succ.mp3"));

             musicAdd->play();
            refresh_mortadha();


        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer Publicite"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

        ui->lineEdit_id1->clear();
        ui->lineEdit_nom1->clear();
        ui->lineEdit_prix1->clear();
        ui->lineEdit_duree1_2->clear();
        ui->lineEdit_idp1->clear();

    }
}

void MainWindow::on_modifier_promo_clicked()
{
    QString id = ui->lineEdit_id_pr_2->text();
    QString nom= ui->lineEdit_nom_pr_2->text();
    int pourc= ui->lineEdit_pourc_2->text().toInt();
    QDate datee =ui->dateEdit_3->date();
    QString id_p= ui->lineEdit_idp_pr_2->text();

    Promotion p (id,nom,pourc,datee,id_p);


    if (ui->lineEdit_id_pr_2->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP IDENTIFIANT!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }

    else if (ui->lineEdit_nom_pr_2->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP Nom!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_idp_pr_2->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP ID PRODUIT!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if ((p.test_pourc(pourc)==false)||(ui->lineEdit_pourc_2->text().isEmpty()))
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP Pourcentage!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }






    else{




        bool test=p.modifier();
        if(test)
        {



            N.notification_modifierPromotion();
            refresh_mortadha();
            musicAdd->setMedia(QUrl("C:/sound/modif succ.mp3"));

             musicAdd->play();
            QMessageBox::information(nullptr, QObject::tr("Modifier une Promotion"),
                                     QObject::tr("Promotion modifiee.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);



        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer Promotion"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

        ui->lineEdit_id_pr_2->clear();
        ui->lineEdit_nom_pr_2->clear();
        ui->lineEdit_pourc_2->clear();
        ui->lineEdit_idp1->clear();

    }
}

void MainWindow::on_supprimer_promo_clicked()
{
    if(ui->afficher_promo->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                 QObject::tr("Veuillez Choisir une Promotion du Tableau.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {   int id=ui->afficher_promo->model()->data(ui->afficher_promo->model()->index(ui->afficher_promo->currentIndex().row(),0)).toInt();
        Promotion p(ui->afficher_promo->model()->data(ui->afficher_promo->model()->index(ui->afficher_promo->currentIndex().row(),0)).toString(),ui->afficher_promo->model()->data(ui->afficher_promo->model()->index(ui->afficher_promo->currentIndex().row(),1)).toString(),ui->afficher_promo->model()->data(ui->afficher_promo->model()->index(ui->afficher_promo->currentIndex().row(),2)).toInt(),ui->afficher_promo->model()->data(ui->afficher_promo->model()->index(ui->afficher_promo->currentIndex().row(),3)).toDate(),ui->afficher_promo->model()->data(ui->afficher_promo->model()->index(ui->afficher_promo->currentIndex().row(),4)).toString());



        QString str = " Vous voulez vraiment supprimer \n la Promotion :";
        int ret = QMessageBox::question(this, tr("Promotion"),str,QMessageBox::Ok|QMessageBox::Cancel);

        switch (ret) {
        case QMessageBox::Ok:
            if (p.supprimer(id)){
                N.notification_supprimerPromotion();
                musicAdd->setMedia(QUrl("C:/Users/Lenovo/Desktop/onsss/ONS/sound/supp succ.mp3"));

                 musicAdd->play();
                refresh_mortadha();

                QMessageBox::information(0, qApp->tr("Suppression"),

                                         qApp->tr("Publicite suprimée"), QMessageBox::Cancel);

            }
            else
            {

                QMessageBox::critical(0, qApp->tr("Suppression"),
                                      qApp->tr("Promotion non trouvé "), QMessageBox::Cancel);
            }



            break;
        case QMessageBox::Cancel:

            break;
        default:
            // should never be reached
            break;
        }


    }
}

void MainWindow::on_tri_croissant_promo_clicked()
{
    ui->afficher_promo->setModel(tmp_promotion.tricroissant());
}

void MainWindow::on_tri_decroissant_promo_clicked()
{
    ui->afficher_promo->setModel(tmp_promotion.trideccroissant());
}

void MainWindow::on_pb_ajouter_mortadha_2_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    QString nom= ui->lineEdit_nom_3->text();
    int prix= ui->lineEdit_prix_3->text().toInt();
    QString duree=ConvertirTime();
    QString id_p= ui->lineEdit_idp_3->text();
    Publicite e(id,nom,prix,duree,id_p);



    if (ui->lineEdit_id_3->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP IDENTIFIANT!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }

    else if (ui->lineEdit_nom_3->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP nom!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_prix_3->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP prix!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_idp_3->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP id produit!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else{

        bool test=e.ajouter();
        if(test)
        {

            refresh_mortadha();
            N.notification_ajoutPublicite();
            musicAdd->setMedia(QUrl("C:/sound/ajout succe.mp3"));

             musicAdd->play();

            QMessageBox::information(0, qApp->tr("Ajout"),

                                     qApp->tr("Publicite ajoutée"), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter une Publicite"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
}



void MainWindow::on_promo_recherche_returnPressed()
{
    if(ui->promo_recherche->text()!="")
    {       // QString b=ui->comboBox_recherche_Promotion_2_2->currentText();
        QString a=ui->promo_recherche->text();
        ui->afficher_promo->setModel(tmp_promotion.displayClause("WHERE (ID LIKE '%"+a+"%' OR NOM LIKE '%"+a+"%' OR POURCENTAGE LIKE '%"+a+"%' OR DATEE LIKE '%"+a+"%' OR ID_P LIKE '%"+a+"%' )"));
    }
    else
        ui->afficher_promo->setModel(tmp_promotion.afficher());
}

void MainWindow::on_pub_ajouter_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    QString nom= ui->lineEdit_nom_3->text();
    int prix= ui->lineEdit_prix_3->text().toInt();
    QString duree=ConvertirTime();
    QString id_p= ui->lineEdit_idp_3->text();
    Publicite e(id,nom,prix,duree,id_p);



    if (ui->lineEdit_id_3->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP IDENTIFIANT!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }

    else if (ui->lineEdit_nom_3->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP nom!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_prix_3->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP prix!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_idp_3->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP id produit!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else{

        bool test=e.ajouter();
        if(test)
        {

            refresh_mortadha();
            N.notification_ajoutPublicite();
            musicAdd->setMedia(QUrl("C:/sound/ajout succe.mp3"));

             musicAdd->play();

            QMessageBox::information(0, qApp->tr("Ajout"),

                                     qApp->tr("Publicite ajoutée"), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter une Publicite"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_radioButton_10_clicked()
{

}

void MainWindow::on_pub_modifier_clicked()
{

    int id=ui->lineEdit_id1->text().toInt();
    int prix = ui->lineEdit_prix1->text().toInt();
    QString nom = ui->lineEdit_nom1->text();
    QString duree = ui->lineEdit_duree1_2->text();
    QString id_p= ui->lineEdit_idp1->text();
    Publicite pub (id,nom,prix,duree,id_p);



    if (ui->lineEdit_id1->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP IDENTIFIANT!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }

    else if (ui->lineEdit_nom1->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP nom!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_prix1->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP prix!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_idp1->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP id produit!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }
    else if (ui->lineEdit_duree1_2->text().isEmpty())
    {

        QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP DUREE!!!!") ;
        QMessageBox::critical(0, qApp->tr("Ajout"),

                              qApp->tr("Probleme d'ajout"), QMessageBox::Cancel);

    }

    else{

      bool test=pub.modifier();
        if(test)
        {
            //QMessageBox::information(this," Modifier "," Votre Publicite est modifiée") ;
            QMessageBox::information(0, qApp->tr("Modification"),

                                     qApp->tr("Publicite Modifiée"), QMessageBox::Cancel);


            N.notification_modifierPublicite();
            musicAdd->setMedia(QUrl("C:/sound/modif succ.mp3"));

             musicAdd->play();
            refresh_mortadha();


        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer Publicite"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }

        ui->lineEdit_id1->clear();
        ui->lineEdit_nom1->clear();
        ui->lineEdit_prix1->clear();
        ui->lineEdit_duree1_2->clear();
        ui->lineEdit_idp1->clear();

    }
}

void MainWindow::on_pub_supprimer_clicked()
{
    if(ui->Publicite_affichage_2->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                 QObject::tr("Veuillez Choisir une Publicite du Tableau.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {   int id=ui->Publicite_affichage_2->model()->data(ui->Publicite_affichage_2->model()->index(ui->Publicite_affichage_2->currentIndex().row(),0)).toInt();
        Publicite pub(ui->Publicite_affichage_2->model()->data(ui->Publicite_affichage_2->model()->index(ui->Publicite_affichage_2->currentIndex().row(),0)).toInt(),ui->Publicite_affichage_2->model()->data(ui->Publicite_affichage_2->model()->index(ui->Publicite_affichage_2->currentIndex().row(),1)).toString(),ui->Publicite_affichage_2->model()->data(ui->Publicite_affichage_2->model()->index(ui->Publicite_affichage_2->currentIndex().row(),2)).toInt(),ui->Publicite_affichage_2->model()->data(ui->Publicite_affichage_2->model()->index(ui->Publicite_affichage_2->currentIndex().row(),3)).toString(),ui->Publicite_affichage_2->model()->data(ui->Publicite_affichage_2->model()->index(ui->Publicite_affichage_2->currentIndex().row(),4)).toString());



        QString str = " Vous voulez vraiment supprimer \n la publicite :";
        int ret = QMessageBox::question(this, tr("Publicite"),str,QMessageBox::Ok|QMessageBox::Cancel);

        switch (ret) {
        case QMessageBox::Ok:
            if (pub.supprimer(id)){
                N.notification_supprimerPublicite();
                musicAdd->setMedia(QUrl("C:/sound/supp succ.mp3"));

                 musicAdd->play();
                refresh_mortadha();
                QMessageBox::information(0, qApp->tr("Suppression"),

                                         qApp->tr("Publicite Supprimée"), QMessageBox::Cancel);

            }
            else
            {

                QMessageBox::critical(0, qApp->tr("Suppression"),
                                      qApp->tr("Publicite non trouvé "), QMessageBox::Cancel);
            }



            break;
        case QMessageBox::Cancel:

            break;
        default:
            // should never be reached
            break;
        }


    }
}

void MainWindow::on_tri_croissant_publicite_2_clicked()
{
    ui->Publicite_affichage_2->setModel(tmp_publicite.tricroissant());

}

void MainWindow::on_tri_deccroissant_publicite_2_clicked()
{
    ui->Publicite_affichage_2->setModel(tmp_publicite.trideccroissant());
}

void MainWindow::on_recherche_Publicite_2_returnPressed()
{
    if(ui->recherche_Publicite_2->text()!="")
    {        //QString b=ui->comboBox_recherche_Publicite_2->currentText();
        QString a=ui->recherche_Publicite_2->text();
        ui->Publicite_affichage_2->setModel(tmp_publicite.displayClause("WHERE (ID LIKE '%"+a+"%' OR NOM LIKE '%"+a+"%' OR PRIX LIKE '%"+a+"%' OR DUREE LIKE '%"+a+"%' OR ID_P LIKE '%"+a+"%') "));
    }
    else
        ui->Publicite_affichage_2->setModel(tmp_publicite.afficher());
}

void MainWindow::on_pdf_publicite_2_clicked()
{
    QPdfWriter pdf("C:/PdfPublicite.pdf");
    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(2300,1200,"Liste Des Publicite");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 50));
    // painter.drawText(1100,2000,afficheDC);
    painter.drawRect(1500,200,7300,2600);
    //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
    painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(300,3300,"ID");
    painter.drawText(2300,3300,"NOM");
    painter.drawText(4300,3300,"PRIX");
    painter.drawText(6300,3300,"DUREE");
    painter.drawText(8000,3300,"IDP");



    QSqlQuery query;
    query.prepare("select * from PUBLICITE");
    query.exec();
    while (query.next())
    {
        painter.drawText(300,i,query.value(0).toString());
        painter.drawText(2300,i,query.value(1).toString());
        painter.drawText(4300,i,query.value(2).toString());
        painter.drawText(6300,i,query.value(3).toString());
        painter.drawText(8000,i,query.value(4).toString());



        i = i +500;
    }
    int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/ilyes/Documents/PdfPublicite.pdf"));

        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}






void MainWindow::on_send_clicked()
{
    smtp = new Smtp("aveaveyro15@gmail.com" , "ellaba200", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    msg=ui->message_mail->toPlainText();

    smtp->sendMail("ilyes_test",ui->a_mail->text(),ui->objet_mail->text(),msg);

    QMessageBox::information(nullptr, QObject::tr("SENT"),
                             QObject::tr("Email Sended Successfully.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_excel_clicked()
{
    QTableView *table;
    table = ui->afficher_promo;

    QString filters("CSV files (*.csv);;All files (*.*)");
    QString defaultFilter("CSV files (*.csv)");
    QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                       filters, &defaultFilter);
    QFile file(fileName);

    QAbstractItemModel *model =  table->model();
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream data(&file);
        QStringList strList;
        for (int i = 0; i < model->columnCount(); i++) {
            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
            else
                strList.append("");
        }
        data << strList.join(";") << "\n";
        for (int i = 0; i < model->rowCount(); i++) {
            strList.clear();
            for (int j = 0; j < model->columnCount(); j++) {

                if (model->data(model->index(i, j)).toString().length() > 0)
                    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") + "\n";
        }
        file.close();
        QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
    }
}
