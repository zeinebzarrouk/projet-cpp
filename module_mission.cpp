
#include "module_mission.h"
#include "ui_module_mission.h"
#include "mission.h"
#include "journaliste.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>
#include <QTextStream>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QDate>



module_mission::module_mission(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::module_mission)
{
    ui->setupUi(this);
    this->setWindowTitle("Module mission");
    ui->tabjournaliste->setModel(tmpjournaliste.afficher());
    ui->tabmission->setModel(tmpmission.afficher());
}

module_mission::~module_mission()
{
    delete ui;
}

bool module_mission::verifID1()
{
    if (ui->lineEdit_id_3->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_id_3->text().isEmpty())
    {
        ui->lineEdit_id_3->clear();

        ui->lineEdit_id_3->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}

bool module_mission::verifNOM1()
{
    if (ui->lineEdit_nom->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_nom->text().isEmpty())
    {
        ui->lineEdit_nom->clear();
        ui->lineEdit_nom->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}

bool module_mission::verifPRENOM()
{
    if (ui->lineEdit_prenom->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_prenom->text().isEmpty())
    {
        ui->lineEdit_prenom->clear();
        ui->lineEdit_prenom->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}

bool module_mission::verifSPECIALITE()
{
    if (ui->lineEdit_prenom_2->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_prenom_2->text().isEmpty())
    {
        ui->lineEdit_prenom_2->clear();
        ui->lineEdit_prenom_2->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }
}




bool module_mission::verifNUM()
{
    if (ui->lineEdit_num->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_num->text().isEmpty())
    {
        ui->lineEdit_num->clear();

        ui->lineEdit_num->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}







//ajout journaliste
void module_mission::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString adresse= ui->lineEdit_adresse->text();
    QString specialite= ui->lineEdit_prenom_2->text();
    int num = ui->lineEdit_num->text().toInt();
    srand (time(NULL));
    QDate d = QDate::currentDate() ;
     QString datee =d.toString("dd / MM / yyyy ") ;
     QString fn="ajouter" ;
    QString nom1 = ui->lineEdit_nom->text();
  journalisteh pp(nom1,datee,fn) ;
  bool test1=pp.ajoutehis() ;



  journaliste e(id,nom,prenom,adresse,specialite,num);
  if(verifID1()&&verifNOM1()&&verifPRENOM()&&verifSPECIALITE()&&verifNUM()){
  bool test=e.ajouter();
  if(test)
{

      ui->tabjournaliste->setModel(tmpjournaliste.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un journaliste"),
                  QObject::tr("journaliste ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un journaliste"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

}



//supprimer journaliste
void module_mission::on_pushButton_4_clicked()
{
    int id = ui->lineEdit_id_5->text().toInt();
    bool test=tmpjournaliste.supprimer(id);
    srand (time(NULL));
    QDate d = QDate::currentDate() ;
     QString datee =d.toString("dd / MM / yyyy ") ;
     QString fn="supprimer" ;
    QString nom1 = ui->lineEdit_nom->text();
  journalisteh pp(nom1,datee,fn) ;
  bool test1=pp.modifierhis() ;
    if(test)
    {ui->tabjournaliste->setModel(tmpjournaliste.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un journaliste"),
                    QObject::tr("journaliste supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Partenaire"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

//recherche journa
void module_mission::on_pushButton_9_clicked()
{
    int id;

           id=ui->lineEdit_2->text().toInt();
       bool test= true;
       if(test==(true))
       {
          ui->tabjournaliste->setModel(tmpjournaliste.rechercher(id));
   }
}

//modif journa
void module_mission::on_pushButton_3_clicked()
{
       int id= ui->lineEdit_nom_2->text().toInt();
       QString adresse=ui->lineEdit_nom_5->text();
       int num=ui->lineEdit_nom_4->text().toInt();


               bool test=tmpjournaliste. modifier(id,adresse,num);
               srand (time(NULL));
               QDate d = QDate::currentDate() ;
                QString datee =d.toString("dd / MM / yyyy ") ;
                QString fn="modifier" ;
               QString nom1 = ui->lineEdit_nom->text();
             journalisteh pp(nom1,datee,fn) ;
             bool test1=pp.modifierhis() ;
                  if (test)
                  {ui->tabjournaliste->setModel(tmpjournaliste.afficher());//refresh
                      QMessageBox::information(nullptr, QObject::tr("Modifier un patient"),
                                  QObject::tr("patient modifié.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

                  }
                  else
                      QMessageBox::critical(nullptr, QObject::tr("Modifier un patient"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);






}


void module_mission::on_pushButton_10_clicked()
{
    ui->tabjournaliste->setModel( tmpjournaliste.afficher_tri());
   // ui->tabjournaliste->setModel( tmpjournaliste.afficher_tri());


}



bool module_mission::verifID()
{
    if (ui->lineEdit_id1->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_id1->text().isEmpty())
    {
        ui->lineEdit_id1->clear();

        ui->lineEdit_id1->setPlaceholderText("contient que des chiffres") ;
        return false;
    }
    else
    {
        return true;
    }

}

bool module_mission::verifNOM()
{
    if (ui->lineEdit_nom_3->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_nom_3->text().isEmpty())
    {
        ui->lineEdit_nom_3->clear();
        ui->lineEdit_nom_3->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}







//ajout journa

void module_mission::on_pushButton_5_clicked()
{
    int id = ui->lineEdit_id1->text().toInt();
    QString nom= ui->lineEdit_type->text();
    QString type= ui->lineEdit_nom_3->text();
    QString localisation= ui->lineEdit_nom_6->text();




  mission e(id,nom,type,localisation);
  if(verifID()&&verifNOM())
  {
  bool test=e.ajouter();
  if(test)
{

      ui->tabmission->setModel(tmpmission.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un miss"),
                  QObject::tr("journaliste ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un miss"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
}
void module_mission::on_pushButton_7_clicked()
{
    int id = ui->lineEdit_5->text().toInt();
    bool test=tmpmission.supprimer(id);
    if(test)
    {ui->tabmission->setModel(tmpmission.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un miss"),
                    QObject::tr("journaliste supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un miss"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void module_mission::on_pushButton_6_clicked()
{
    int id= ui->lineEdit_4->text().toInt();
    QString type=ui->lineEdit->text();
    QString localisation=ui->lineEdit_3->text();


            bool test=tmpmission. modifier(id,type,localisation);
               if (test)
               {ui->tabmission->setModel(tmpmission.afficher());//refresh
                   QMessageBox::information(nullptr, QObject::tr("Modifier un mission"),
                               QObject::tr("mission modifié.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

               }
               else
                   QMessageBox::critical(nullptr, QObject::tr("Modifier un mission"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);






}


void module_mission::on_pushButton_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->tabmission->model()->rowCount();
        const int columnCount = ui->tabmission->model()->columnCount();

        out <<  "<html>\n"
               "<head>\n"
               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("strTitle")
            <<  "</head>\n"
               "<body bgcolor=#ffffff link=#5000A0>\n"

               //     "<align='right'> " << datefich << "</align>"
               "<center> <H1>GESTION MISSION </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

        // headers
        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->tabmission->isColumnHidden(column))
                out << QString("<th>%1</th>").arg(ui->tabmission->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";

        // data table
        for (int row = 0; row < rowCount; row++) {
            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tabmission->isColumnHidden(column)) {
                    QString data = ui->tabmission->model()->data(ui->tabmission->model()->index(row, column)).toString().simplified();
                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                }
            }
            out << "</tr>\n";
        }
        out <<  "</table> </center>\n"
               "</body>\n"
               "</html>\n";

        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer (QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        doc.setHtml(strStream);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}

void module_mission::on_pushButton_8_clicked()
{
    QTableView *table;
                          table = ui->tabmission;
                          QString filters("CSV files (.csv);;All files (.*)");
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

void module_mission::on_pushButton_11_clicked()
{
    ui->tabmission_2->setModel(tmph.afficherhis()) ;
    ui->tabmission_2->setModel(tmph.afficherhis());//refresh
}




