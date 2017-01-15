/*************************************************************************
                           Fichier  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Fichier> (fichier Fichier.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Fichier.h"

//------------------------------------------------------------- Constantes
const char SEP = ' ';
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Fichier::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Fichier & Fichier::operator = ( const Fichier & unFichier )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Fichier::Fichier ( const Fichier & unFichier )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Fichier>" << endl;
#endif
} //----- Fin de Fichier (constructeur de copie)


/*Fichier::Fichier(string c, Informations i) ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Fichier>" << endl;
#endif
} //----- Fin de Fichier*/


Fichier::~Fichier ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Fichier>" << endl;
#endif
} //----- Fin de ~Fichier


//------------------------------------------------------------------ PRIVE
istream & operator >> (istream & is, Fichier & f)
{   getline(is, f.Infos.ip, SEP);
    getline(is, f.Infos.logname, SEP);
    getline(is, f.Infos.name, SEP);
    getline(is, f.Infos.date, SEP);
    getline(is, f.Infos.requete, SEP);
    getline(is, f.cible, SEP);
    getline(is, f.Infos.status, SEP);
    getline(is, f.Infos.data, SEP);
    getline(is, f.Infos.referent, SEP);
    getline(is, f.Infos.navigateur);
    return is;
}

ostream & operator << (ostream & os, Fichier & f)
{   os << f.Infos.ip << SEP << f.Infos.logname << SEP << f.Infos.name << SEP << f.Infos.date << SEP << f.Infos.requete << SEP << f.cible << SEP << f.Infos.status;
    os << SEP << f.Infos.data << SEP << f.Infos.referent << SEP << f.Infos.navigateur << endl;
    return os;
}
//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

