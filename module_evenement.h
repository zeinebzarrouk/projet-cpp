#ifndef MODULE_EVENEMENT_H
#define MODULE_EVENEMENT_H

#include <QDialog>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
#include<QObject>
namespace Ui {
class module_evenement;
}

class module_evenement : public QDialog
{
    Q_OBJECT

public:
    explicit module_evenement(QWidget *parent = nullptr);
    ~module_evenement();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_login_clicked();
    void myfunction();

private:
    Ui::module_evenement *ui;
    QTimer *timer;
};

#endif // MODULE_EVENEMENT_H
