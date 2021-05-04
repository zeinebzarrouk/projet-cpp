#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "module_article.h"
#include "module_evenement.h"
#include "module_employe.h"

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    void afficher_module_article();
    ~menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::menu *ui;
    module_article Module_article;
    module_evenement Module_evenement;
    employe Module_employe;
};

#endif // MENU_H
