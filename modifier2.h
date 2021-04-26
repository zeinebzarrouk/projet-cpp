#ifndef MODIFIER2_H
#define MODIFIER2_H

#include <QWidget>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class modifier2;
}

class modifier2 : public QDialog
{
    Q_OBJECT

public:
    explicit modifier2(QWidget *parent = nullptr);
    bool check_id(QString id);
    ~modifier2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::modifier2 *ui;
};

#endif // MODIFIER2_H
