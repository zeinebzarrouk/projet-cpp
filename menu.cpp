#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);

    QPixmap bkgnd("C:/Users/sofia/OneDrive/Documents/integration_projet_cpp/bck_menu.jpg");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Background, bkgnd);
       this->setPalette(palette);
}

menu::~menu()
{
    delete ui;
}
void menu::afficher_module_article()
{
    //this->hide();
    Module_article.show();

}
void menu::on_pushButton_clicked()
{
afficher_module_article();
}

void menu::on_pushButton_3_clicked()
{
    Module_employe.show();
}

void menu::on_pushButton_2_clicked()
{
    Module_evenement.show();
}
