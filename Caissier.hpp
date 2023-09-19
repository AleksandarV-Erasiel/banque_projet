#ifndef __CAISSIER_H
#define __CAISSIER_H
#include "Client.hpp"

class Banque;

/**
 * @brief La classe Caissier représente un caissier de la banque.
 */
class Caissier
{
protected:
    Banque *_banque;
    double _tempsMoyenService;
    int _nbClients;
    double _tempsServiceTotal;
    bool _estLibre;
    double _dureeOccupee;

public:
    /**
     * @brief Constructeur de la classe Caissier.
     * @param banque Pointeur vers la banque à laquelle le caissier est associé.
     * @param tempsMoyenService Le temps moyen de service par client.
     */
    Caissier(Banque *banque, double tempsMoyenService);

    /**
     * @brief Récupère le temps moyen de service par client.
     * @return Le temps moyen de service.
     */
    double tempsMoyenService();

    /**
     * @brief Récupère le nombre de clients servis par le caissier.
     * @return Le nombre de clients.
     */
    int nbClients();

    /**
     * @brief Calcule le taux d'occupation du caissier.
     * @return Le taux d'occupation en pourcentage.
     */
    double tauxOccupation();

    /**
     * @brief Vérifie si le caissier est libre.
     * @return `true` si le caissier est libre, sinon `false`.
     */
    bool estLibre();

    /**
     * @brief Démarre le service d'un client par le caissier.
     * @param client Le client à servir.
     */
    void servir(Client &client);

    /**
     * @brief Attend que le caissier soit libre.
     */
    void attendre();

    /**
     * @brief Récupère la durée pendant laquelle le caissier est occupé.
     * @return La durée d'occupation du caissier.
     */
    double dureeOccupee();
};

#endif
