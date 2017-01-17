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

#include "CollectionDeLog.h"

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

    if (e == 'e'){
        exclusion = true;
    }else{
        exclusion = false;
    }

    if (h != -1){
        heure = h;
    }

    if (topdix == 'o'){
        RemplirMapTopDix(nf);
        AfficherTopDix();
    }else if (topdix == 'g'){
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
                //verification
                if( (exclusion && l.GetType() !="js") && ( heure != -1 && l.GetHeure() == heure) ) { // j'ai pas mis les extensions -> faire collection
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

    typedef multimap <int, string> setTopDix;
    setTopDix mySetTopDix;

    mapTopDix::const_iterator itmap;

    for(auto itmap = myMapTopDix.begin(); itmap != myMapTopDix.end(); ++itmap){
        mySetTopDix.insert(make_pair(itmap->second, itmap->first));
    }

    int compt =0;
    setTopDix::const_iterator itset;

    cout << "Le top 10 est :" << endl;

    for(itset = mySetTopDix.begin(); compt >10 && itset !=mySetTopDix.end(); ++itset){

        cout << "page : " << itset->second << " " << itset->first << " hits." << endl; // a changer avec la syntaxe du tp
        compt++;

    }

    cout << "fin du top 10 !" << endl;

}

void CollectionDeLog::EnregistrerGraph(string nfGraph){
#ifdef MAP
    cout << "Appel de EnregistrerGraph de <CollectionDeLog>" << endl;
#endif

}
