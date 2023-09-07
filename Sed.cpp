#include <iostream>
using namespace std;
#include "Sed.hpp"
#include "Evenement.hpp"

Sed::Sed(double t0) {
    _heure = t0;
}

void Sed::ajouter(Evenement &evenement) {
    _evenements.insert(evenement);
}

void Sed::lancer() {
    while (!_evenements.empty()) {
        Evenement e1 = *_evenements.begin();
        double t1 = e1.heure();
        _heure = t1;
        e1.traiter();
        _evenements.erase(e1);
    }
}

double Sed::heure() {
    return _heure;
}