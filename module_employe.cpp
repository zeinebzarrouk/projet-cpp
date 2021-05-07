#include "module_employe.h"
#include "ui_module_employe.h"
#include "personnel.h"
#include "fonction.h"
#include <QMessageBox>
#include "mailing.h"
//#include "statis.h"
#include "qcustomplot/qcustomplot.h"
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>

employe::employe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employe)
{
    this->setWindowTitle("Module employe");
    ui->setupUi(this);//
    ui->tableView_employe->setModel(etmp.afficher());
    ui->tableView_fonction->setModel(ftmp.afficherFonct());
    employe::StatsPerso();

      //employe::makeplot();

}

employe::~employe()
{
    delete ui;
}
void employe::StatsPerso(){
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->StatPerso->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    QCPBars *regen = new QCPBars(ui->StatPerso->xAxis, ui->StatPerso->yAxis);

    regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders

    regen->setStackingGap(1);

    // set names and colors:

    regen->setName("Stat perso");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other:
    /*nuclear->moveAbove(fossil);
    regen->moveAbove(nuclear);*/

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 ;
    labels << "Directeur" << "Marketing" << "Communication" << "GRH" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->StatPerso->xAxis->setTicker(textTicker);
    ui->StatPerso->xAxis->setTickLabelRotation(60);
    ui->StatPerso->xAxis->setSubTicks(false);
    ui->StatPerso->xAxis->setTickLength(0, 4);
    ui->StatPerso->xAxis->setRange(0, 8);
    ui->StatPerso->xAxis->setBasePen(QPen(Qt::white));
    ui->StatPerso->xAxis->setTickPen(QPen(Qt::white));
    ui->StatPerso->xAxis->grid()->setVisible(true);
    ui->StatPerso->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->StatPerso->xAxis->setTickLabelColor(Qt::white);
    ui->StatPerso->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->StatPerso->yAxis->setRange(0, 12.1);
    ui->StatPerso->yAxis->setPadding(5); // a bit more space to the left border
    ui->StatPerso->yAxis->setLabel("Power Consumption in\nKilowatts per Capita (2007)");
    ui->StatPerso->yAxis->setBasePen(QPen(Qt::white));
    ui->StatPerso->yAxis->setTickPen(QPen(Qt::white));
    ui->StatPerso->yAxis->setSubTickPen(QPen(Qt::white));
    ui->StatPerso->yAxis->grid()->setSubGridVisible(true);
    ui->StatPerso->yAxis->setTickLabelColor(Qt::white);
    ui->StatPerso->yAxis->setLabelColor(Qt::white);
    ui->StatPerso->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->StatPerso->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> regenData;

    regenData   << 1 << 2 << 3 << 4 ;

    regen->setData(ticks, regenData);

    // setup legend:
    ui->StatPerso->legend->setVisible(true);
    ui->StatPerso->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->StatPerso->legend->setBrush(QColor(255, 255, 255, 100));
    ui->StatPerso->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->StatPerso->legend->setFont(legendFont);
    ui->StatPerso->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
/*void statis::make()
{
        int male;
        int femelle;
        int total;
        QString Male;
        QString Femelle;

        QSqlQuery q;

        q.prepare("SELECT COUNT(id_ab) FROM etudiant where etat ='Male' ");
        q.exec();
        q.first() ;
        Male=(q.value(0).toInt());

        q.prepare("SELECT COUNT(id_ab) FROM etudiant where etat ='Femelle' ");
        q.exec();
        q.first() ;
        Femelle=(q.value(0).toInt());
        q.prepare("SELECT COUNT(id_ab) FROM etudiant ");
        q.exec();
        q.first() ;
        total=(q.value(0).toInt());

        femelle=((double)femelle/(double)total)*100;
        male=100-femelle;

        Male= QString::number(male);
        Femelle=QString::number(femelle);
        QPieSeries *series;
         series= new  QPieSeries();
         series->append("MALE"+Male+"%",male);
         series->append("FEMELLE"+Femelle+"%",femelle);
         QPieSlice *slice0 = series->slices().at(0);
          slice0->setLabelVisible();

          QPieSlice *slice1 = series->slices().at(1);
             slice1->setExploded();
             slice1->setLabelVisible();
             slice1->setPen(QPen(Qt::darkRed, 2));
             slice1->setBrush(Qt::black);

              QChart *chart = new QChart();
              chart->addSeries(series);
              chart->setTitle("Statistiques sur l'etat des animaux ");
              chart->legend()->show();
              QChartView *chartView = new QChartView(chart);
              chartView->setRenderHint(QPainter::Antialiasing);
              ui->verticalLayout->addWidget(chartView);

}*/
void employe::on_ajouter_fonction_clicked()
{

        int id=ui->id_fonction->text().toInt();
        int nbheure=ui->nb_heure->text().toInt();

    QString nom =ui->nom->text();
    QString diplome =ui->diplome->text();
    QString caract =ui->caract->toPlainText();


    if ((id!=0 && nbheure!=0 && nom!="" && diplome!="" && caract!="" ))
    {

    fonction f(  id , nom , caract,nbheure,diplome);
      bool test=f.ajouterFonct();
      if(test)
      {
       ui->tableView_employe->setModel(ftmp.afficherFonct());
          QMessageBox::information(nullptr,QObject::tr("ok!"),
                                   QObject::tr("fonction ajouté avec succès.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);
      }
      else
          QMessageBox::information(nullptr,QObject::tr("not ok!"),
                                   QObject::tr("fonction non ajouté.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);

    }
}

void employe::on_modifier_fonction_clicked()
{
    int id=ui->text_idf->text().toInt();
int nbheure=ui->nb_heure->text().toInt();

QString nom =ui->nom->text();
QString diplome =ui->diplome->text();
QString caract =ui->text_caractf->toPlainText();


if ((id!=0  && nom!=""  && caract!="" ))
{

fonction f(  id , nom , caract,nbheure,diplome);
  bool test=f.modifierFonct(id,nom,caract);
  if(test)
  {
       ui->tableView_fonction->setModel(ftmp.afficherFonct());
      QMessageBox::information(nullptr,QObject::tr("updated!"),
                               QObject::tr("function update.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);
  }
  else

      QMessageBox::information(nullptr,QObject::tr("updated!"),
                               QObject::tr("not update.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);

}

}

void employe::on_supprimer_fonction_clicked()
{
    int id=ui->idsupf->text().toInt();
int nbheure=ui->nb_heure->text().toInt();

QString nom =ui->nom->text();
QString diplome =ui->diplome->text();
QString caract =ui->caract->toPlainText();


if ((id!=0 ))
{

fonction f(  id , nom , caract,nbheure,diplome);
  bool test=f.supprimerFonct(id);
  if(test)
  {
       ui->tableView_fonction->setModel(ftmp.afficherFonct());
      QMessageBox::information(nullptr,QObject::tr("deleted!"),
                               QObject::tr("function delete.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);
  }
  else

      QMessageBox::information(nullptr,QObject::tr("updated!"),
                               QObject::tr("not delete.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);

}

}

void employe::on_ajouter_clicked()
{
    int id=ui->id->text().toInt();
    int salaire=ui->salaire->text().toInt();
    int tel=ui->tel->text().toInt();

QString nomPrenom =ui->nomPrenom->text();
QString login =ui->login->text();
QString email =ui->email->text();
QString adresse =ui->adresse->text();
QString grade =ui->grade->text();
QString cin =ui->cin->text();

if ((id!=0 && salaire!=0 && nomPrenom!="" && login!="" && email!="" && adresse!="" && grade!="" && tel!=0 && cin!="" ))
{

personnel p( nomPrenom,id ,cin ,adresse,tel,salaire,grade,email, login);
  bool test=p.ajouterEmpl();
  if(test)
  {
   ui->tableView_employe->setModel(p.afficher());
      QMessageBox::information(nullptr,QObject::tr("ok!"),
                               QObject::tr("employé ajouté avec succès.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);
  }
  else
      QMessageBox::information(nullptr,QObject::tr("not ok!"),
                               QObject::tr("empoye non ajouté.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);
}
}

void employe::on_modifier_clicked()
{
    int id=ui->text_id->text().toInt();
    int salaire=ui->text_salaire->text().toInt();
     QString grade=ui->text_grade->text();
     int tel=ui->tel->text().toInt();

 QString nomPrenom =ui->nomPrenom->text();
 QString login =ui->login->text();
 QString email =ui->email->text();
 QString adresse =ui->adresse->text();
 QString cin =ui->cin->text();


 if ((id!=0 && salaire!=0 && grade!=""))
 {

       personnel e( nomPrenom , id , cin , adresse,tel,salaire,grade,email, login);
     bool test=e.modifier(id,salaire,grade);
     if(test)
     {
          ui->tableView_employe->setModel(etmp.afficher());
         QMessageBox::information(nullptr,QObject::tr("updated!"),
                                  QObject::tr("employee update.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);
     }
     else
     {
         QMessageBox::information(nullptr,QObject::tr("updated!"),
                                  QObject::tr("not update.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);
      }
}
}

void employe::on_supprimer_employe_clicked()
{

        int id= ui->idSup->text().toInt();
        int salaire=ui->salaire->text().toInt();
         QString grade=ui->grade->text();
         int tel=ui->tel->text().toInt();

     QString nomPrenom =ui->nomPrenom->text();
     QString login =ui->login->text();
     QString email =ui->email->text();
     QString adresse =ui->adresse->text();
     QString cin =ui->cin->text();
     if((id!=0))
     {
        personnel etmp( nomPrenom , id , cin , adresse,tel,salaire,grade,email, login);
        bool test=etmp.supprimer(id);

        if(test)
        {
            ui->tableView_employe->setModel(etmp.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok!"),
                                     QObject::tr("employee delete.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);
        }

        else
            QMessageBox::information(nullptr,QObject::tr("not ok!"),
                                     QObject::tr("not delete.\n""Cliquez Cancel to exit."),QMessageBox::Cancel);

    }



}


void employe::on_tri_id_clicked()
{
ui->tableView_employe->setModel(etmp.trier_id());
}

void employe::on_tri_grade_clicked()
{
ui->tableView_employe->setModel(etmp.trier_grade());
}

void employe::on_tri_nom_clicked()
{
ui->tableView_employe->setModel(etmp.trier_nom());
}

void employe::on_lineEdit_textChanged(const QString &arg1)
{
    QString rech;
         rech= arg1.toCaseFolded();
           QSqlQueryModel * model= new QSqlQueryModel();
       QSqlQuery* qry=new QSqlQuery();

        qry->prepare("SELECT * from employe where nomPrenom like concat (:rech,'%')   or id like concat (:rech,'%') or grade like concat (:rech,'%')     ");
        qry->bindValue(":rech",rech);
        qry->exec();
        model->setQuery(*qry);
        ui->tableView_employe->setModel(model);
}



void employe::on_mailing_list_clicked()
{
    //this->hide();
   mailing mailing;
    mailing.setModal(true);
    mailing.exec();
}
bool employe::verifNOM_PRENOM()
{
    if (ui->nomPrenom->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->nomPrenom->text().isEmpty())
    {
        ui->nomPrenom->clear();
        ui->nomPrenom->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool employe::verifID()
{
    if (ui->id->text().contains(QRegExp("[^0-9 ]") ) || ui->id->text().isEmpty())
    {
        ui->id->clear();

        ui->id->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}

void employe::on_imprimer_clicked()
{

    //QDateTime datecreation = date.currentDateTime();
            //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                   QPdfWriter pdf("");
                   QPainter painter(&pdf);
                  int i = 4000;
                       painter.setPen(Qt::blue);
                       painter.setFont(QFont("Arial", 30));
                       painter.drawText(1100,1200,"Liste Du personnel ");
                       painter.setPen(Qt::black);
                       painter.setFont(QFont("Arial", 50));
                       painter.drawRect(100,100,7300,2600);

                       painter.drawRect(0,3000,9600,500);
                       painter.setFont(QFont("Arial", 9));
                       painter.drawText(200,3300,"ID");
                       painter.drawText(3200,3300,"NOMPRENOM");
                       painter.drawText(3200,3300,"N_CIN");
                        painter.drawText(3200,3300,"ADRESSE");
                         painter.drawText(3200,3300,"N_TEL");
                          painter.drawText(3200,3300,"SALAIRE");
                           painter.drawText(3200,3300,"GRADE");
                            painter.drawText(3200,3300,"EMAIL");
                             painter.drawText(3200,3300,"LOGIN");


                       QSqlQuery query;
                       query.prepare("select * from employe");
                       query.exec();
                       while (query.next())
                       {
                           painter.drawText(200,i,query.value(0).toString());
                           painter.drawText(3200,i,query.value(1).toString());
                           painter.drawText(3200,i,query.value(2).toString());
                                 painter.drawText(3200,i,query.value(2).toString());
                                painter.drawText(3200,i,query.value(2).toString());
                               painter.drawText(3200,i,query.value(2).toString());
                              painter.drawText(3200,i,query.value(2).toString());
                              painter.drawText(3200,i,query.value(2).toString());
                             painter.drawText(3200,i,query.value(2).toString());


                          i = i + 500;
                       }
                       int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                           if (reponse == QMessageBox::Yes)
                           {
                               QDesktopServices::openUrl(QUrl::fromLocalFile("emplacement du projet"));
                               painter.end();
                           }
                           if (reponse == QMessageBox::No)
                           {
                                painter.end();
                           }
}
