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
#include <vector>
#include <algorithm>
#include "CollectionDeLog.h"
using namespace std;

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

class const_iterator;

class const_iterator;

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


CollectionDeLog::CollectionDeLog(string nf, char e, int h, char topdix, string nfGraph) {
#ifdef MAP
    cout << "Appel au constructeur de <CollectionDeLog>" << endl;
#endif

    if (e = 'e'){
        exclusion = true;
    }else{
        exclusion = false;
    }

    if (h != -1){
        heure = h;
    }else{
        heure = -1;
    }

    if (topdix ='o'){
        RemplirMapTopDix(nf);
        AfficherTopDix();
    }else if (topdix = 'g'){
        RemplirMapGraph(nf);
        EnregistrerGraph(nfGraph);
    }

}


CollectionDeLog::~CollectionDeLog() {
#ifdef MAP
    cout << "Appel au destructeur de <CollectionDeLog>" << endl;
#endif
}

void CollectionDeLog::RemplirMapTopDix(string nf) {
#ifdef MAP
    cout << "Appel de AjouterTopDix de <CollectionDeLog>" << endl;
#endif

    Log l;

    ifstream file ( nf.c_str() );
        if(file.good()){
            while(file >> l){
                //verification du triE
                if( (exclusion && l.GetType() !="js") && l.GetHeure() == heure ) { // j'ai pas mis les extensions
                    //verification de l'existence de la cible
                    if (myMapTopDix.find(l.cible) != myMapTopDix.end()) {
                        myMapTopDix[l.cible] += 1;
                    } else {
                        if(!l.cible.empty()){
                            myMapTopDix.insert(make_pair(l.cible, 1));
                        }
                    }
                }
            }
        }

}

void CollectionDeLog::RemplirMapGraph(string nf) {
#ifdef MAP
    cout << "Appel de AjouterGraph de <CollectionDeLog>" << endl;
#endif

}


void CollectionDeLog::AfficherTopDix() const {
#ifdef MAP
    cout << "Appel de AfficherTopDix de <CollectionDeLog>" << endl;
#endif

    Log l;

    vector<int, string> vectorTopDix();
    mapGraph::const_iterator it;

    for(it = myMapGraph.begin(); it != myMapGraph.end(); ++it){
        //vector.insert();
    }

    //sort(vectorTopDix.begin(), vectorTopDix.end());

    int compteur =0;

    cout << "Le top 10 est :" << endl;
/*
    for(it = myMapTopDix.begin() ; compteur >10 ; ++it){
        cout << "page : " << it->first << " " << it->second << " hits." << endl; // a changer avec la syntaxe du tp
        compteur++;
    }

    cout << "fin du top 10 !" << endl;
*/
}

void CollectionDeLog::EnregistrerGraph(string nfGraph) const {
#ifdef MAP
    cout << "Appel de EnregistrerGraph de <CollectionDeLog>" << endl;
#endif

}
