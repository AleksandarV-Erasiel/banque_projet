#include <iostream>
using namespace std;
#include "FileAttente.hpp"
#include "Client.hpp"

FileAttente::FileAttente(Banque *banque) {
    _banque = banque;
    _longueurMax = 0;
    _longueurMoyenne = 0, _tempsMoyenAttente = 0;
}

int FileAttente::longueurMax() {
    return _longueurMax;
}

double FileAttente::longueurMoyenne() {
    return _longueurMoyenne;
}

double FileAttente::tempsMoyenAttente() {
    return _tempsMoyenAttente;
}

void FileAttente::ajouter(Client &client) {
    _clients.push(client);
    if (_longueurMax < _clients.size()) _longueurMax = (int) _clients.size();
    // _longueurMoyenne += (int) _clients.size();
    // _longueurMoyenne /= 2;
}

bool FileAttente::estVide() {
    return _clients.empty();
}

Client &FileAttente::retirer() {
    Client &c = _clients.front();
    _tempsMoyenAttente += _banque->heure() - c.heureArrivee();
    _tempsMoyenAttente /= 2;
    _clients.pop();
    _longueurMoyenne += (int) _clients.size();
    _longueurMoyenne /= 2;
    return c;
}

void FileAttente::afficherListeClients() {
    cout << "File Attente :" << endl;
    queue<Client> tempQueue = _clients;

    while (!tempQueue.empty()) {
        const Client& client = tempQueue.front();
        cout << client.heureArrivee() << " ";
        tempQueue.pop();
    }
    cout << endl;
}

queue<Client> FileAttente::clientsQueue() {
    return _clients;
}
