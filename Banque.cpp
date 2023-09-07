#include <iostream>
using namespace std;
#include "Banque.hpp"
#include "FileAttente.hpp"
#include "Sed.hpp"
#include "Arrivee.hpp"

Banque::Banque(double t0, double dureePrevue, int nbCaissiers, double *caissiers, double tempsEntreArrivees): Sed(t0) {
    _dureePrevue = dureePrevue;
    _nbCaissiers = nbCaissiers;
    _tempsEntreArrivees = tempsEntreArrivees;
    Caissier **caissiersList = new Caissier*[nbCaissiers];
    for (int i=0; i < nbCaissiers; i++) {
        Caissier *c = new Caissier(this, caissiers[i]);
        caissiersList[i] = c;
    }
    _caissiers = caissiersList;

    Arrivee* arrivee = new Arrivee(banque, 4.0);
    banque->ajouter(*arrivee);
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
    while (!caissierLibre) {
        if (_caissiers[i]->estLibre())
            caissierLibre = _caissiers[i];
        i++;
    }
    return caissierLibre;
}

FileAttente *Banque::fileAttente() {
    return _fileAttente;
}