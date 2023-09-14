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
    double heureArrivee() const;
};
#endif