#include <iostream>
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
    if (cs) {
        cs->servir(*c);
    } else { banque->fileAttente()->ajouter(*c); }
    double hpa = _heure + (rand() % (4 - 2 + 1)) + 2; // TODO: faire en sorte de faire une distribution normal with th standard deviation
    if (hpa <= banque->dureePrevue()) {
        Arrivee *a = new Arrivee(banque, hpa);
        banque->ajouter(*a);
    }
}