#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"employe.h"
#include<QString>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int cin = ui->cin->text().toInt();
       QString nom = ui->nom->text();
       QString prenom=ui->prenom->text();
       QString poste=ui->poste->text();
       QString salaire=ui->salaire->text();
       QString email=ui->email->text();



           employe e (cin,nom,prenom,poste,salaire,email);
           bool test = e.ajouter();



         if( test){
             ui->tableView->setModel(Etmp.afficher());


              QMessageBox::information(nullptr, QObject::tr("ok"),
                          QObject::tr("ajout effectué .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

      }
          else
              QMessageBox::critical(nullptr, QObject::tr("not ok"),
                          QObject::tr("ajout non effectué .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_supprimer_clicked()
{
    int cin = ui->cin->text().toInt();

           bool test = Etmp.supprimer(cin);



         if( test){
             ui->tableView->setModel(Etmp.afficher());


              QMessageBox::information(nullptr, QObject::tr("ok"),
                          QObject::tr("suppression effectué .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

      }
          else
              QMessageBox::critical(nullptr, QObject::tr("not ok"),
                          QObject::tr("suppression non effectué .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_modifier_clicked()
{
    int cin = ui->cin->text().toInt();
       QString nom = ui->nom->text();
       QString prenom=ui->prenom->text();
       QString poste=ui->poste->text();
       QString salaire=ui->salaire->text();
       QString email=ui->email->text();



           employe e (cin,nom,prenom,poste,salaire,email);
           bool test = Etmp.modifier(cin);



         if( test){


              QMessageBox::information(nullptr, QObject::tr("ok"),
                          QObject::tr("modification effectué .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

      }
          else
              QMessageBox::critical(nullptr, QObject::tr("not ok"),
                          QObject::tr("modification non effectué .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}




