#ifndef __BANQUE_H
#define __BANQUE_H
#include "Caissier.hpp"
#include "Sed.hpp"

class FileAttente;
class Banque:public Sed
{
protected:
    FileAttente *_fileAttente;
    double _dureePrevue, _tempsEntreArrivees;
    Caissier **_caissiers;
    int _nbCaissiers;
public:
    Banque(double t0, double dureePrevue, double *caissiers, double tempsEntreArrivees);
    ~Banque();
    double dureePrevue();
    int nbCaissiers();
    double tempsEntreArrivees();
    double dureeReelle();
    int nbClients();
    Caissier unCaissierLibre();
};
#endif