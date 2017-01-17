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

    nomFichier = nf;
    if (e == 'e'){
        exclusion = true;
    }else{
        exclusion = false;
    }
    heure = h;

    if (topdix == 'o'){
        AfficherTopDix();
    }else if (topdix == 'g'){
        EnregistrerGraph(nfGraph);
    }

}


CollectionDeLog::~CollectionDeLog() {
#ifdef MAP
    cout << "Appel au destructeur de <CollectionDeLog>" << endl;
#endif
}

void CollectionDeLog::RemplirMapTopDix(){
#ifdef MAP
    cout << "Appel de AjouterTopDix de <CollectionDeLog>" << endl;
#endif
    if(heure!=-1) cout << "Warning : only hits between " << heure << "h and "<< heure+1 << "h have been taken into account" << endl;
    Log l;

    ifstream file ( nomFichier.c_str() );
        if(file.good()){
            while(file >> l){
                //verification
                int s = 0;
                if(isdigit(l.Infos.status[0])) s= stoi(l.Infos.status);
                if(s==200) {
                    if (((exclusion && exclus.find(l.GetType()) == exclus.end()) &&
                         (heure != -1 && l.GetHeure() == heure)) || (!exclusion && heure == -1) ||
                        (!exclusion && heure != -1 && l.GetHeure() == heure) || (heure == -1 && (exclusion &&
                                                                                                 exclus.find(
                                                                                                         l.GetType()) ==
                                                                                                 exclus.end()))) { // j'ai pas mis les extensions -> faire collection
                        //verification de l'existence de la cible
                        if (myMapTopDix.size() != 0 && myMapTopDix.find(l.cible) != myMapTopDix.end()) {
                            myMapTopDix[l.cible] += 1;
                        } else {
                            if (!l.cible.empty()) {
                                myMapTopDix.insert(make_pair(l.cible, 1));
                            }
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

void CollectionDeLog::AfficherTopDix(){
#ifdef MAP
    cout << "Appel de AfficherTopDix de <CollectionDeLog>" << endl;
#endif
    RemplirMapTopDix();
    Log l;

    typedef multimap <int, string> setTopDix;
    setTopDix mySetTopDix;

    mapTopDix::const_iterator itmap;
    for(itmap = myMapTopDix.begin(); itmap != myMapTopDix.end(); ++itmap){
        mySetTopDix.insert(make_pair(itmap->second, itmap->first));
    }

    int compt =0;
    setTopDix::const_iterator itset;

    for(itset = mySetTopDix.end() ; compt <11 && itset !=mySetTopDix.begin(); --itset){
        if(itset!=mySetTopDix.end()) {
            cout << itset->second << " (" << itset->first << " hits)" << endl; // a changer avec la syntaxe du tp
        }
        compt++;

    }
    if(compt<11) cout << itset->second << "  (" << itset->first << " hits)" << endl; // a changer avec la syntaxe du tp

}

void CollectionDeLog::EnregistrerGraph(string nfGraph){
#ifdef MAP
    cout << "Appel de EnregistrerGraph de <CollectionDeLog>" << endl;
#endif

    cout << "Dot-file " << nfGraph << " generated" << endl;
    AfficherTopDix();
    RemplirMapGraph(nfGraph);
}
