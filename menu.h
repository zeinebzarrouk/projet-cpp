#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "module_article.h"

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

private:
    Ui::menu *ui;
    module_article Module_article;
};

#endif // MENU_H
