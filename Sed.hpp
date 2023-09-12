#ifndef __SED_H
#define __SED_H
#include "Evenement.hpp"
#include <set>
#include <vector>
using namespace std;

// bool compareEvenements(Evenement* lhs, Evenement* rhs) {
//     return lhs->heure() < rhs->heure();
// }

class Sed
{
protected:
    double _heure;
    std::vector<Evenement*> _evenements;
public:
    Sed(double t0);
    void ajouter(Evenement& e);
    void lancer();
    double heure();
};
#endif