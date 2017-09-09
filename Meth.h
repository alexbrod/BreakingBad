//
// Created by vladimir khotyakov on 06/09/2017.
//

#ifndef BREAKINGBAD_METH_H
#define BREAKINGBAD_METH_H

class Meth{

protected:
    int price;
    int purety;
    int amount;

public:
    Meth(int price, int purety, int amount) : price(price), purety(purety), amount(amount) {}

    Meth() {
        price =0;
        purety = 0;
        amount = 0;
    }

    int getPrice() const {
        return price;
    }

    void setPrice(int price) {
        Meth::price = price;
    }

    int getPurety() const {
        return purety;
    }

    void setPurety(int purety) {
        Meth::purety = purety;
    }

    int getAmount() const {
        return amount;
    }

    void setAmount(int amount) {
        Meth::amount = amount;
    }

};

#endif //BREAKINGBAD_METH_H
