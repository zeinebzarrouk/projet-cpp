#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QtSql>
#include<QMessageBox>
#include <QFileInfo>
#include "employe.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_login_clicked();

private:
    Ui::MainWindow *ui;
     QSqlDatabase mydb;
};
#endif // MAINWINDOW_H
