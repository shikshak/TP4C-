//---------- Interface de la classe <CollectionDeLog> (fichier CollectionDeLog.h) ----------------
#if ! defined ( CollectionDeLog_H )
#define CollectionDeLog_H

//--------------------------------------------------- Interfaces utilisées
#include<string>
#include<map>
#include <iostream>

#include "cmake-build-debug/Log.h"
#include "Log.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CollectionDeLog>
//
//
//------------------------------------------------------------------------

class CollectionDeLog
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

//-------------------------------------------- Constructeurs - destructeur

    CollectionDeLog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    CollectionDeLog (const CollectionDeLog & unCollectionDeLog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :char e='n'
    //

    CollectionDeLog(string nf, char e, char topdix = 'o', string nfGraph = "unnamed.dot"); //nom du fichier, e pour le tri n pour pas de tri, o si top dix n si graph, nom du fichier .dot
    CollectionDeLog (string nf, int heure, char topdix = 'o', string nfGraph = "unnamed.dot");
    CollectionDeLog (string nf, char e, int heure, char topdix = 'o', string nfGraph = "unnamed.dot");

    virtual ~CollectionDeLog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjouterTopDix(Log & l);
    void AjouterGraph(Log & l);
    void AjouterTopDixInv(Log & l);

    void AjouterTopDix (string nf, char triE='n'); //n pas de tri, e on fait le tri
    void AjouterTopDix (string nf, int heure);
    void AjouterTopDix (string nf, char triE, int heure);

    void AjouterGraph (string nf, char triE);
    void AjouterGraph (string nf, int heure);
    void AjouterGraph (string nf, char triE, int heure);

    void AfficherTopDix (ostream & os = cout) const;
    void EnregistrerGraph (string nfGraph) const;

//------------------------------------------------------------------ PRIVE



protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    typedef map <string,int> mapTopDix; //cible, compteur
    static mapTopDix myMapTopDix;

    typedef map <int,string> mapTopDixInv; //compteur, cible
    static mapTopDixInv myMapTopDixInv;

    typedef map <string,Informations> mapGraph; //cibleref, structure inforamtions
    static  mapGraph myMapGraph;

    friend class Log;

};

//-------------------------------- Autres définitions dépendantes de <CollectionDeLog>

#endif // CollectionDeLog_H
