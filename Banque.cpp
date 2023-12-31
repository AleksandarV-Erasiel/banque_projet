#include <algorithm>
#include <iostream>
using namespace std;
#include "Banque.hpp"
#include "FileAttente.hpp"
#include "Sed.hpp"
#include "Arrivee.hpp"

Banque::Banque(double t0, double dureePrevue, int nbCaissiers, double *caissiers, double tempsEntreArrivees): Sed(t0) {
    cout << "PARAMETRES D'ENTREES" << endl;
    cout << "Duree prevue: " << dureePrevue << endl;
    cout << "Nombre de Caissiers: " << nbCaissiers << endl;
    cout << "Duree de traitement des Caissiers: [ ";
    for (int i = 0; i < nbCaissiers; ++i) {
        cout << caissiers[i] << " ";
    }
    cout << "]" << endl;
    cout << "Temps entre arrivees: " << tempsEntreArrivees << endl;
    cout << "==================================================================================================================" << endl;

    _dureePrevue = dureePrevue;
    _dureeReelle = dureePrevue;
    _nbCaissiers = nbCaissiers;
    _tempsEntreArrivees = tempsEntreArrivees;

    _fileAttente = new FileAttente(this);

    Caissier **caissiersList = new Caissier*[nbCaissiers];
    for (int i=0; i < nbCaissiers; i++) {
        Caissier *c = new Caissier(this, caissiers[i]);
        caissiersList[i] = c;
    }
    
    _caissiers = caissiersList;

    Arrivee* arrivee = new Arrivee(this, 0.0);
    ajouter(*arrivee);
}

Banque::~Banque() {
    for (int i = 0; i < _nbCaissiers; i++) {
        delete _caissiers[i];
    }
    delete [] _caissiers;
}

double Banque::dureePrevue() {
    return _dureePrevue;
}

int Banque::nbCaissiers() {
    return _nbCaissiers;
}

double Banque::tempsEntreArrivees() {
    return _tempsEntreArrivees;
}

double Banque::dureeReelle() {
    return _dureeReelle;
}

int Banque::nbClients() {
    int nbClients = 0;
    for (int i = 0; i < _nbCaissiers; i++) {
        nbClients += _caissiers[i]->nbClients();
    }
    return nbClients;
}

Caissier *Banque::unCaissierLibre() {
    Caissier *caissierLibre = NULL;
    int i = 0;
    for (i = 0; i < _nbCaissiers; i++) {
        if (_heure >= _caissiers[i]->dureeOccupee() && _caissiers[i]->estLibre()) {
            caissierLibre = _caissiers[i];
            break;
        }
    }

    return caissierLibre;
}

double** Banque::tauxOccupationParCaissier() {
    int nbCaissiers = _nbCaissiers;
    double** tauxOccupation = new double*[nbCaissiers];

    for (int i = 0; i < nbCaissiers; ++i) {
        tauxOccupation[i] = new double;
        *(tauxOccupation[i]) = _caissiers[i]->tauxOccupation();
    }
    return tauxOccupation;
}

double Banque::dureeReelleCalculation() {
    for (int i = 0; i < _nbCaissiers; ++i) {
        if (_caissiers[i]->dureeOccupee() > _dureeReelle) {
            _dureeReelle = _caissiers[i]->dureeOccupee();
        }
    }
    return _dureeReelle;
}


FileAttente *Banque::fileAttente() {
    return _fileAttente;
}