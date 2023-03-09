#include "employe.h"
#include<QString>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

employe::employe(int cin,QString nom,QString prenom,QString poste,QString salaire,QString email)
{
     this->cin=cin;
     this->nom=nom;
     this->prenom=prenom;
     this->poste=poste;
     this->salaire=salaire;
     this->email=email;

}
int employe:: getCIN(){return cin;}
QString employe:: getNom(){return nom ;}
QString employe::getPrenom(){return prenom ;}
QString employe:: getPoste(){return poste ;}
QString employe:: getSalaire(){return salaire;}
QString employe::getEmail(){return email ;}

void employe:: setCIN(int cin){this->cin=cin;}
void employe:: setNom(QString nom){this->nom=nom;}
void employe:: setPrenom(QString prenom){this->prenom=prenom;}
void employe:: setPoste(QString poste){this->poste=poste;}
void employe:: setSalaire(QString salaire){this->salaire=salaire;}
void employe:: setEmail(QString email){this->email=email;}

bool employe :: ajouter()
{
    QSqlQuery query;
   QString res=QString::number(cin);
    query.prepare("insert into employee (cin, nom, prenom,poste,salaire,email)" " VALUES (:cin, :nom, :prenom,:poste,:salaire, :email)");

    query.bindValue(":cin", res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":poste",poste);
    query.bindValue(":salaire", salaire);
    query.bindValue(":email",email);

    return    query.exec();
}
QSqlQueryModel * employe ::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM employee");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("poste"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("email"));





    return model;
}
bool employe :: supprimer (int cin )
{
    QSqlQuery query;
    query.prepare("Delete from employee where CIN = :cin ");
    query.bindValue(":cin", cin);
    return    query.exec();
}
bool employe::modifier(int cin ){

    QString cin_string=QString::number(cin);

    QSqlQuery query;
    query.prepare(" UPDATE employee SET cin= :cin ,nom= :nom, prenom=:prenom,"
                  " poste= :poste ,salaire= :salaire, email=:email where cin= :cin");

    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":poste",poste);
    query.bindValue(":salaire", salaire);
    query.bindValue(":email",email);

    return    query.exec();

}
