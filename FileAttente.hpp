#ifndef __FILEATTENTE_H
#define __FILEATTENTE_H
#include "Client.hpp"
#include "Banque.hpp"
#include <queue>
using namespace std;

class Banque;
class FileAttente
{
protected:
    Banque *_banque;
    queue<Client> _clients;
    int _longueurMax;
    double _longueurMoyenne;
    double _tempsMoyenAttente;
public:
    FileAttente(Banque *banque);
    int longueurMax();
    double longueurMoyenne();
    double tempsMoyenAttente();
    void ajouter(Client& client);
    bool estVide();
    Client& retirer();
};
#endif