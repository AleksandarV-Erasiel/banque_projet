#include <iostream>
using namespace std;
#include "Sed.hpp"
#include "Arrivee.hpp"
#include "Client.hpp"
#include "Caissier.hpp"
#include "FileAttente.hpp"

Arrivee::Arrivee(Sed *sed, double heure): Evenement(sed, heure) {

}

void Arrivee::traiter() {
    Client *c = new Client(_heure);
    Caissier *cs = _sed.unCaissierLibre();
    if (cs) {
        cs->servir(c);
    } else { _sed.fileAttente().ajouter(c); }
    double hpa = _heure + (rand() % (4 - 2 + 1)) + 2; // TODO: faire en sorte de faire une distribution normal with th standard deviation
    if (hpa <= _sed.dureePrevue()) { 
        Arrivee *a = new Arrivee(_sed, hpa);
        _sed->ajouter(a);
    }
}