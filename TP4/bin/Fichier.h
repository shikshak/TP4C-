/*************************************************************************
                           Fichier  -  Header de la classe Fichier
                             -------------------
    début                : 10/01/2017
    copyright            : (C) $2017$ par $Julien Charles-Nicolas$
    e-mail               : $julien.charles-nicolas@insa-lyon.fr$
*************************************************************************/

//---------- Interface du module <Fichier> (fichier Fichier.h) -------------------
#ifndef TP4_FICHIER_H
#define TP4_FICHIER_H

//------------------------------------------------------------------------
// Rôle du module <Fichier>
// Modélise les lignes du .log en objet Fichier
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
struct Informations
{   string ip;
    string logname;
    string name;
    string date;
    string requete;
    string type;
    string status;
    string data;
    string referent;
    string navigateur;
    Informations(string i="", string l="", string na="", string d="", string r="", string t="", string s="", string da="", string re="", string n=""):ip(i) ,logname(l), name(na), date(d), requete(r), type(t), status(s), data(da), referent(re), navigateur(n){}
};


class Fichier
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Fichier & operator = ( const Fichier & unFichier );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Fichier ( const Fichier & unFichier );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Fichier (string c="", Informations i=Informations()): cible(c), Infos(i){};
    // Mode d'emploi :
    // Crée un fichier vide
    // Contrat :
    //

    virtual ~Fichier ( );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    string cible;
    Informations Infos;
//---------------------------------------------------------- Classes amies
    friend istream & operator >> (istream& is, Fichier& f);
    friend ostream & operator << (ostream& os, Fichier& f);
    friend class CollectionDeFichiers;
//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//---------------------------------------------- Types dépendants de <Fichier>


#endif // TP4_FICHIER_H
