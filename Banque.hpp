#ifndef __BANQUE_H
#define __BANQUE_H
#include "Caissier.hpp"
#include "Sed.hpp"
#include "FileAttente.hpp"

class FileAttente;
/**
 * @brief La classe Banque représente la banque et le coeur de notre simulation.
 */
class Banque:public Sed
{
protected:
    FileAttente *_fileAttente;
    double _dureePrevue, _dureeReelle, _tempsEntreArrivees;
    Caissier **_caissiers;
    int _nbCaissiers;
public:
    /**
     * Constructeur de la classe Banque.
     * @param t0 Temps initial.
     * @param dureePrevue Durée prévue de la simulation.
     * @param nbCaissiers Nombre de caissiers.
     * @param caissiers Tableau des durées de traitement des caissiers.
     * @param tempsEntreArrivees Temps entre les arrivées des clients.
     */
    Banque(double t0, double dureePrevue, int nbCaissiers, double *caissiers, double tempsEntreArrivees);
    
    /**
     * Destructeur de la classe Banque.
     */
    ~Banque();

    /**
     * Récupère la durée prévue de la simulation.
     * @return La durée prévue.
     */
    double dureePrevue();

    /**
     * Récupère le nombre de caissiers de la banque.
     * @return Le nombre de caissiers.
     */
    int nbCaissiers();

    /**
     * Récupère le temps entre les arrivées des clients.
     * @return Le temps entre les arrivées.
     */
    double tempsEntreArrivees();

    /**
     * Récupère la durée réelle de la simulation.
     * @return La durée réelle.
     */
    double dureeReelle();

    /**
     * Récupère le nombre total de clients dans la banque.
     * @return Le nombre total de clients.
     */
    int nbClients();

    /**
     * Cherche un caissier libre dans la banque.
     * @return Un caissier libre s'il existe, sinon NULL.
     */
    Caissier *unCaissierLibre();

    /**
     * Récupère le taux d'occupation de chaque caissier.
     * @return Un tableau de taux d'occupation.
     */
    double **tauxOccupationParCaissier();

    /**
     * Calcule la durée réelle de la simulation.
     * @return La durée réelle.
     */
    double dureeReelleCalculation();

    /**
     * Récupère la file d'attente de la banque.
     * @return La file d'attente.
     */
    FileAttente *fileAttente();
};
#endif