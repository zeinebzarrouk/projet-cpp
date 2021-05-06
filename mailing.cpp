#include "mailing.h"
#include "ui_mailing.h"
#include <QMainWindow>
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include "employe.h"


mailing::mailing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mailing)
{
    ui->setupUi(this);
    connect(ui->send, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exit, SIGNAL(clicked()),this, SLOT(close()));
}
void mailing::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void mailing::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    this->hide();
   employe employe;
    employe.setModal(true);
    employe.exec();
}

mailing::~mailing()
{
    delete ui;
}


void mailing::on_send_clicked()
{

}
