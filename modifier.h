#ifndef MODIFIER_H
#define MODIFIER_H

#include <QDialog>
#include <QSqlQuery>
#include <QtDebug>
#include <QMessageBox>
#include <mainwindow.h>
#include <ui_mainwindow.h>

namespace Ui {
class modifier;
}

class modifier : public QDialog
{
    Q_OBJECT

public:
    explicit modifier(QWidget *parent = nullptr);

     bool check_id(QString id);

    ~modifier();

private slots:
     void on_pushButton_clicked();

private:
    Ui::modifier *ui;
    //ainwindow
};

#endif // MODIFIER_H
