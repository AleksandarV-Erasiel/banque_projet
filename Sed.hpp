#ifndef __SED_H
#define __SED_H
#include "Evenement.hpp"
#include <set>
using namespace std;

class Sed
{
protected:
    double _t0;
    set<Evenement> _evenements;
public:
    Sed(double t0);
    ~Sed();
    void ajouter(Evenement event);
    void lancer();
    double heure();
};
#endif