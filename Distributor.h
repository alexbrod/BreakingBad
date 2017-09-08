//
// Created by vladimir khotyakov on 07/09/2017.
//

#ifndef _DISTRIBUTOR_H
#define _DISTRIBUTOR_H

#include "Client.h"
#include "Meth.h"
#include "DrugDealer.h"
#include "Coock.h"

class Distributor: public DrugDealer{

protected:
    Client* clients;
    Coock* coocks;
    Meth meth;

public:

    Distributor(int id, char* name = NULL, float balance = 0, int fee = 0):
            Person(id, name, balance), DrugDealer(id, name, balance),meth(0,0,0){cout << "Distributor::Distributor\n";}

    Distributor(const Distributor& distributor) = delete;
    ~Distributor(){cout << "Distributor::~Distributor\n";}

    Client *getClients() const {
        return clients;
    }

    void setClients(Client *clients) ;

    Coock *getCoocks() const {
        return coocks;
    }

    void setCoocks(Coock *coocks) ;

    const Meth &getMeth() const {
        return meth;
    }

    void setMeth(const Meth &meth) ;


    void addClient(const Client& client);

    void addCoocks(const Coock& coock);

    bool checkClinet(const Client client);


    virtual bool operator==(const Person& p) const{}


    virtual void toOs(ostream& os) const
    {
        os << "Distributor balanse:" << balance << " ";
    }


};

#endif //BREAKINGBAD_DISTRIBUTOR_H