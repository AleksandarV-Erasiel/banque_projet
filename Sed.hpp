#ifndef __SED_H
#define __SED_H
#include "Evenement.hpp"

class Sed
{
protected:
    
public:
    Sed(int to);
    ~Sed();
    void ajouter(Evenement event);
    void lancer();
    double heure();
};
#endif