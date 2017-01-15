/*************************************************************************
                           CollectionDeLog  -  description
                             -------------------
    début                : 10 janv. 2017
    copyright            : (C) 2017 par jcharlesni
*************************************************************************/

//---------- Réalisation du module <CollectionDeLog> (fichier CollectionDeLog.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include <fstream>
#include "CollectionDeLog.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

CollectionDeLog::CollectionDeLog ( ){
#ifdef MAP
    cout << "Appel au constructeur de <CollectionDeLog>" << endl;
#endif
}

CollectionDeLog::CollectionDeLog (const CollectionDeLog & unCollectionDeLog){
#ifdef MAP
    cout << "Appel au constructeur de <CollectionDeLog>" << endl;
#endif
}

CollectionDeLog::CollectionDeLog(string nf, char e, char topdix, string nfGraph) {
#ifdef MAP
    cout << "Appel au constructeur de <CollectionDeLog>" << endl;
#endif
}

CollectionDeLog::CollectionDeLog (string nf, int heure, char topdix, string nfGraph){
#ifdef MAP
    cout << "Appel au constructeur de <CollectionDeLog>" << endl;
#endif
}

CollectionDeLog::CollectionDeLog(string nf, char e, int heure, char topdix, string nfGraph) {
#ifdef MAP
    cout << "Appel au constructeur de <CollectionDeLog>" << endl;
#endif
}

CollectionDeLog::~CollectionDeLog() {
#ifdef MAP
    cout << "Appel au destructeur de <CollectionDeLog>" << endl;
#endif
}


void CollectionDeLog::AjouterTopDix(Log & l) {
#ifdef MAP
    cout << "Appel de AjouterTopDix de <CollectionDeLog>" << endl;
#endif

    if(!l.cible.empty()){
        myMapTopDix.insert(make_pair(l.cible, 1));
    }
}

void CollectionDeLog::AjouterGraph(Log &l) {
#ifdef MAP
    cout << "Appel de AjouterTopDix de <CollectionDeLog>" << endl;
#endif

    if(!l.cible.empty()){
        myMapGraph.insert(make_pair(l.cible, 1));
    }
}

void CollectionDeLog::AjouterTopDixInv(Log & l) {
#ifdef MAP
    cout << "Appel de AjouterTopDix de <CollectionDeLog>" << endl;
#endif

    if(!l.cible.empty()){
        myMapTopDixInv.insert(make_pair(l.cible, 1));
    }
}


void CollectionDeLog::AjouterTopDix(string nf, char triE) {
#ifdef MAP
    cout << "Appel de AjouterTopDix de <CollectionDeLog>" << endl;
#endif

    Log l;
    l.cible;
    l.Infos.type;

    ifstream file ( nf.c_str() ){
        if(file.good()){
            while(file >> l){
                //verification du triE
                if(triE = 'n' || (triE = 'e' && (l.Infos.type != "jpg" && l.Infos.type != "js" ))) { // rajouter toutes les extensions du tp
                    //verification de l'existence de la cible
                    if (myMapTopDix.find(l.cible) != myMapTopDix.end()) {
                        myMapTopDix[l.cible] += 1;
                    } else {
                        AjouterTopDix(l);
                    }
                }
            }
        }
    }
}

void CollectionDeLog::AjouterTopDix(string nf, int heure) {
#ifdef MAP
    cout << "Appel de AjouterTopDix de <CollectionDeLog>" << endl;
#endif

    Log l;

    ifstream file ( nf.c_str() ){
        if(file.good()){
            while(file >> l){
                //verification du triE
                if(l.Infos.heure == heure) {
                    //verification de l'existence de la cible
                    if (myMapTopDix.find(l.cible) != myMapTopDix.end()) {
                        myMapTopDix[l.cible] += 1;
                    } else {
                        AjouterTopDix(l);
                    }
                }
            }
        }
    }
}

void CollectionDeLog::AjouterTopDix(string nf, char triE, int heure) {
#ifdef MAP
    cout << "Appel de AjouterTopDix de <CollectionDeLog>" << endl;
#endif

    Log l;

    ifstream file ( nf.c_str() ){
        if(file.good()){
            while(file >> l){
                //verification du triE
                if((triE == 'n' || (triE == 'e' && (l.Infos.type != "jpg" && l.Infos.type != "ios" ))) && l.Infos.heure == heure ) { // j'ai pas mis les extensions
                    //verification de l'existence de la cible
                    if (myMapTopDix.find(l.cible) != myMapTopDix.end()) {
                        myMapTopDix[l.cible] += 1;
                    } else {
                        AjouterTopDix(l);
                    }
                }
            }
        }
    }
}

void CollectionDeLog::AjouterGraph(string nf, char triE) {
#ifdef MAP
    cout << "Appel de AjouterGraph de <CollectionDeLog>" << endl;
#endif

    string ciblref;



}

void CollectionDeLog::AjouterGraph(string nf, int heure) {
#ifdef MAP
    cout << "Appel de AjouterGraph de <CollectionDeLog>" << endl;
#endif

}

void CollectionDeLog::AjouterGraph(string nf, char triE, int heure) {
#ifdef MAP
    cout << "Appel de AjouterGraph de <CollectionDeLog>" << endl;
#endif

}


void CollectionDeLog::AfficherTopDix(ostream & os = cout) const {
#ifdef MAP
    cout << "Appel de AfficherTopDix de <CollectionDeLog>" << endl;
#endif

    Log l;
    mapTopDix::const_iterator it;
    int compteur =0;

    cout << "Le top 10 est :" << endl;

    for(it = myMapTopDix.begin() ; compteur >10 ; ++it){
        cout << "page : " << it->first << " " << it->second << " hits." << endl; // a changer avec la syntaxe du tp
        compteur++;
    }

    cout << "fin du top 10 !" << endl;

}

void CollectionDeLog::EnregistrerGraph(string nfGraph) const {
#ifdef MAP
    cout << "Appel de EnregistrerGraph de <CollectionDeLog>" << endl;
#endif

}
