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
    Caissier *cs = banque->unCaissierLibre();
    Client *c = new Client(_heure);

    if (cs != NULL && banque->fileAttente()->estVide() && banque->heure() >= cs->dureeOccupee()) {
        cs->servir(*c);
    } else {
        banque->fileAttente()->ajouter(*c);
    }

    double ecartTypePercentage = 1;
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