#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/Qtdb/mydb2.db");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4_clicked()
{
       ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_5_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString username,password;
    username=ui->lineEdit_username->text();
    password=ui->lineEdit_password->text();

    if(!mydb.open()){
        qDebug()<<"Failed to connect with db";
        return;

    }
    QSqlQuery qry;
    if(qry.exec("select * from Users where Username='"+username+"' and Password='"+password+"'"))
    {
                int count=0;
                while(qry.next())
    {
                count++;

    }
                if(count==1)
    {
                 ui->stackedWidget->setCurrentIndex(3);

    }
                if(count>1)
    {
                ui->label_14->setText("Username and Password is Duplicate");

    }
                if(count<1)
    {
                ui->label_14->setText("Username and Password is Not Correct");

    }


    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString name,email,contct,pasword;
    name=ui->lineEdit->text();
    pasword=ui->lineEdit_2->text();
    contct=ui->lineEdit_4->text();
    email=ui->lineEdit_3->text();


    if(!mydb.open()){
        qDebug()<<"Failed to connect with db";
        return;

    }
    QSqlQuery qry;
    if(qry.exec("insert into Users(Username,Password,Contact,Email) values('"+name+"','"+pasword+"','"+contct+"','"+email+"')"))
    {
        QMessageBox::critical(this,tr("Save"),tr("Saved"));


    }
    else
    {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}
