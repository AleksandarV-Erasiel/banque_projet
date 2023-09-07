#ifndef __SED_H
#define __SED_H
#include "Evenement.hpp"
#include <set>
using namespace std;

class Sed
{
protected:
    double _heure;
    set<Evenement> _evenements;
public:
    Sed(double t0);
    void ajouter(Evenement& event);
    void lancer();
    double heure();
};
#endif