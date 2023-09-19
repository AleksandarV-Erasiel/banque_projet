#ifndef __SED_H
#define __SED_H
#include "Evenement.hpp"
#include <set>
#include <vector>
using namespace std;

/**
 * @brief La classe Sed permet la simulation par événement discrets.
 */
class Sed
{
protected:
    double _heure;
    vector<Evenement*> _evenements;
public:
    /**
     * @brief Constructeur de la classe Sed.
     * @param t0 Le temps initial de la simulation.
     */
    Sed(double t0);

    /**
     * @brief Ajoute un événement à l'échéancier.
     * @param e L'événement à ajouter.
     */
    void ajouter(Evenement& e);

    /**
     * @brief Lance la simulation en traitant les événements dans l'échéancier.
     */
    void lancer();

    /**
     * @brief Obtient l'heure courante de la simulation.
     * @return L'heure courante de la simulation.
     */
    double heure();
};

#endif
