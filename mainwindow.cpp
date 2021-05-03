#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <menu.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Authentification");
   //connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(afficher_menu()));


    QPixmap bkgnd("C:/Users/sofia/OneDrive/Documents/integration_projet_cpp/_1P_6VxA_400x400.jpg");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Background, bkgnd);
       this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficher_menu()
{
    this->hide();

    menu.show();
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->lineEdit->text() == "admin" && ui->lineEdit_2->text() == "admin")
    {
         //QMessageBox::information( 0, tr( "Authentificaton" ), tr( "vous etes connectez" ) );
         afficher_menu();
    }
    else
         QMessageBox::warning( 0, tr( "Authentificaton" ), tr( "Nom d'utilisateur ou mot de passe incorrect ! " ) );
}
