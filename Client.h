//
// Created by vladimir khotyakov on 06/09/2017.
//

#ifndef _CLIENT_H
#define _CLIENT_H

#include "Person.h"


class Client: virtual public Person
{

protected:
    bool isDragUser;

public:
    virtual ~Client(){cout << "Client::~Client\n";}

    Client(int id, char* name = NULL, float balance = 0):
            Person(id, name, balance) {cout << "Client::Client\n";}

    //operators
    virtual bool operator==(const Person& p) const {};
    virtual void toOs(ostream& os) const
    {
        os << "In Client is a drug user:" << isDragUser << " ";
    }

    bool isIsDragUser() const {
        return isDragUser;
    }

    void setIsDragUser(bool isDragUser);

};

#endif

