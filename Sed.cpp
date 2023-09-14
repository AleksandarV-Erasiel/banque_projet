#include <algorithm>
#include <iostream>
using namespace std;
#include "Sed.hpp"
#include "Evenement.hpp"
#include "Arrivee.hpp"
#include "Depart.hpp"

Sed::Sed(double t0) {
    _heure = t0;
}

void Sed::ajouter(Evenement &e) {
    _evenements.push_back(&e);
    // _evenements.insert(&e);
}

void Sed::lancer() {
    while (!_evenements.empty()) {
        // TODO: remove all of these Arrivee, Depart,... etc when debug is finished
        sort(_evenements.begin(), _evenements.end(), [](const Evenement* a, const Evenement* b) {
            return a->heure() < b->heure();
        });


        cout << "Ordre d'arrivee:" << endl;
        for (const Evenement* evenement : _evenements) {
            cout << evenement->heure() << " ";
            
            const Arrivee* arrivee = dynamic_cast<const Arrivee*>(evenement);
            const Depart* depart = dynamic_cast<const Depart*>(evenement);
            
            if (arrivee) {
                cout << "(Arrivee) ";
            } else if (depart) {
                cout << "(Depart) ";
            }
            
            cout << endl;
        }

        cout << endl;
        Evenement* e1 = *_evenements.begin();
        double t1 = e1->heure();
        _heure = t1;
        cout << "_heure = " << _heure << endl; 
        e1->traiter();
        cout << "test" << endl;
        _evenements.erase(_evenements.begin());
        cout << "test" << endl;
        delete e1;
        cout << "test" << endl;

        cout << endl << "======================================" << endl;
    }
}

double Sed::heure() {
    return _heure;
}