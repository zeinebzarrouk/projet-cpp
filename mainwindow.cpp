#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  /*  QPixmap pic("‪‪C:/Users/Gloria/Documents/projet c++/logo0.png");
      ui->label_picture->setPixmap(pic);*/

       mydb=QSqlDatabase::addDatabase("QODBC");
         mydb.setDatabaseName("source_projet2A");
         mydb.setUserName("gloria");
         mydb.setPassword("esprit21");


       if(!mydb.open())
           ui->label->setText("unable to open database");
       else
           ui->label->setText("connected...");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_clicked()
{
    QString username,password;
        username =ui->username->text();
        password=ui->password->text();
    if(!mydb.open())
    {
        QMessageBox::critical(nullptr,QObject::tr(" base de donnée non ouverte"),
                                 QObject::tr("connexion non effectué\n"
                                             "click cancel to exit."), QMessageBox::Cancel
                                 );
    }
      QSqlQuery qry;
        if(qry.exec("select * from employe where LOGIN='"+username+"' and ID='"+password+"'"))
          {
            int count=0;
            while(qry.next())
            {
             count++;
             }
        if(count==1)
        {
            ui->label->setText("username and password are correct");
            this->hide();
            employe employe;
            employe.setModal(true);
            employe.exec();

        }
        if(count>1)
            ui->label->setText("duplicate username and password ");
        if(count<1)
            ui->label->setText("username and password are not correct");
        }

}
