#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include<QString>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
class employe
{
private :
    QString nom ,prenom ,poste ,email,salaire;
    int cin;
public:
    employe(int,QString,QString,QString,QString,QString) ;
    employe(){};
    int getCIN();
    QString getNom();
    QString getPrenom();
    QString getPoste();
    QString getSalaire();
    QString getEmail();

    void setCIN(int  );
    void setNom(QString );
    void setPrenom(QString );
    void setPoste(QString );
    void setSalaire(QString );
    void setEmail(QString );




    bool ajouter();
    bool modifier(int  );
         QSqlQueryModel * afficher();
          bool supprimer(int cin);

};

#endif // EMPLOYE_H
