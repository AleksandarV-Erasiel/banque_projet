#include "Evenement.hpp"

Evenement::Evenement(Sed *sed, double heure) {
    _sed = sed;
    _heure = heure;
}

Evenement::~Evenement() { }

double Evenement::heure() const { return _heure; }

void Evenement::traiter() { }
