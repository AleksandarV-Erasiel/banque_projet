#include "Evenement.hpp"

Evenement::Evenement(Sed *sed, double heure) {
    _sed = sed;
    _heure = heure;
}

double Evenement::heure() { return _heure; }

void Evenement::traiter() { }