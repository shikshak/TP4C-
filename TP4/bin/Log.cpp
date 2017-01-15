/*************************************************************************
                           Log  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Log> (Log Log.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Log.h"

//------------------------------------------------------------- Constantes
const char SEP = ' ';
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Log::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Log & Log::operator = ( const Log & unLog )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Log::Log ( const Log & unLog )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Log>" << endl;
#endif
} //----- Fin de Log (constructeur de copie)


/*Log::Log(string c, Informations i) ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Log>" << endl;
#endif
} //----- Fin de Log*/


Log::~Log ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Log>" << endl;
#endif
} //----- Fin de ~Log


//------------------------------------------------------------------ PRIVE
istream & operator >> (istream & is, Log & f)
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

ostream & operator << (ostream & os, Log & f)
{   os << f.Infos.ip << SEP << f.Infos.logname << SEP << f.Infos.name << SEP << f.Infos.date << SEP << f.Infos.requete << SEP << f.cible << SEP << f.Infos.status;
    os << SEP << f.Infos.data << SEP << f.Infos.referent << SEP << f.Infos.navigateur << endl;
    return os;
}
//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
