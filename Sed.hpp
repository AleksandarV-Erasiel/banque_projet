#ifndef __SED_H
#define __SED_H
#include "Evenement.hpp"
#include <set>
#include <vector>
using namespace std;

class Sed
{
protected:
    double _heure;
    vector<Evenement*> _evenements;
public:
    Sed(double t0);
    void ajouter(Evenement& e);
    void lancer();
    double heure();
};
#endif