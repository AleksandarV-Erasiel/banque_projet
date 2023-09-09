#include <iostream>
#include <random>
using namespace std;
#include "Sed.hpp"
#include "Arrivee.hpp"
#include "Client.hpp"
#include "Caissier.hpp"
#include "FileAttente.hpp"

Arrivee::Arrivee(Banque *sed, double heure): Evenement(sed, heure) {
}

void Arrivee::traiter() {
    Banque* banque = (Banque*) _sed;
    Client *c = new Client(_heure);
    Caissier *cs = banque->unCaissierLibre();



    if (cs != NULL) {
        if (banque->heure() >= cs->dureeOccupee()) cs->servir(*c);
    } else {
        banque->fileAttente()->ajouter(*c);
    }

    cout << "banque->fileAttente->estVide() "<< banque->fileAttente()->estVide() << endl;
    // cout << "banque->fileAttente->clientQueue() " << banque->fileAttente()->clientsQueue().front() << endl;

    // banque->fileAttente()->afficherFile();

    // double hpa = _heure + (rand() % (4 - 2 + 1)) + 2;
    double ecartTypePercentage = 10;
    double ecartType = (banque->tempsEntreArrivees()/100) * ecartTypePercentage;
    random_device rd;
    mt19937 generator(rd());
    normal_distribution<double> distribution(banque->tempsEntreArrivees(), ecartType);
    double hpa = distribution(generator);

    if (banque->heure() + hpa <= banque->dureePrevue()) {
        Arrivee *a = new Arrivee(banque, banque->heure() + hpa);
        banque->ajouter(*a);
    }
}