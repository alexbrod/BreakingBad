//
// Created by vladimir khotyakov on 07/09/2017.
//

#ifndef _DISTRIBUTOR_H
#define _DISTRIBUTOR_H

#include "Client.h"
#include "Meth.h"
#include "DrugDealer.h"
#include "Cook.h"

class Distributor: public DrugDealer{

protected:
    Client** clients;
    Cook** cooks;
    Meth meth;

public:

    Distributor(int id, char* name = NULL, float balance = 0, int fee = 0):
            Person(id, name, balance), DrugDealer(id, name, balance){cout << "Distributor::Distributor\n";}

    Distributor(const Distributor& distributor) = delete;
    ~Distributor(){cout << "Distributor::~Distributor\n";}

    Client **getClients() const {
        return clients;
    }

    void setClients(Client *clients) ;

    Cook **getCooks() const {
        return cooks;
    }

    void setCooks(Cook **cooks) {
        Distributor::cooks = cooks;
    }

    const Meth &getMeth() const {
        return meth;
    }

    void setClients(Client **clients) {
        Distributor::clients = clients;
    }

    void setMeth(const Meth &meth) ;


    void addClient(const Client& client);



    bool checkClient(const Client client);


    virtual bool operator==(const Person& p) const{}


    virtual void toOs(ostream& os) const
    {
        os << "Distributor balance:" << balance << " ";
    }


};

#endif //BREAKINGBAD_DISTRIBUTOR_H
