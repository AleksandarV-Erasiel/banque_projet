#ifndef __EVENEMENT_H
#define __EVENEMENT_H

class Sed;

/**
 * @brief La classe Evenement est une classe de base pour représenter des événements dans la simulation.
 */
class Evenement
{
protected:
    Sed *_sed;    /**< Un pointeur vers la simulation (Sed) associée à l'événement. */
    double _heure; /**< L'heure à laquelle l'événement doit se produire. */

public:
    /**
     * @brief Constructeur de la classe Evenement.
     * @param sed Un pointeur vers la simulation associée à l'événement.
     * @param heure L'heure à laquelle l'événement doit se produire.
     */
    Evenement(Sed *sed, double heure);

    /**
     * @brief Destructeur virtuel de la classe Evenement.
     */
    virtual ~Evenement();

    /**
     * @brief Traite l'événement (cette fonction doit être redéfinie dans les classes dérivées).
     */
    virtual void traiter();

    /**
     * @brief Obtient l'heure à laquelle l'événement doit se produire.
     * @return L'heure de l'événement.
     */
    double heure() const;
};

#endif
