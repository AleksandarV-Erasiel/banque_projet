#ifndef __CLIENT_H
#define __CLIENT_H
// #include <iostream>
// using namespace std;
class Client
{
protected:
    double _heureArrivee;
public:
    Client(double heureArrivee);
    double heureArrivee();
    // friend ostream& operator<<(std::ostream& os, const Client& client);
};

// ostream& operator<<(std::ostream& os, const Client& client)
// {
//     os << "Heure d'arrivee: " << client._heureArrivee;
//     return os;
// }
#endif