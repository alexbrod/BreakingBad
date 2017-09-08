//
// Created by vladimir khotyakov on 07/09/2017.
//

#ifndef BREAKINGBAD_INGREDIENT_H
#define BREAKINGBAD_INGREDIENT_H

class Ingredient{
protected:
    float price;
    int purety;
    int amount;

public:
    Ingredient(float price, int purety, int amount) : price(price), purety(purety), amount(amount) {
    }

    float getPrice() const {
        return price;
    }

    void setPrice(float price) {
        Ingredient::price = price;
    }

    int getPurety() const {
        return purety;
    }

    void setPurety(int purety) {
        Ingredient::purety = purety;
    }

    int getAmount() const {
        return amount;
    }

    void setAmount(int amount) {
        Ingredient::amount = amount;
    }
};

#endif //BREAKINGBAD_INGREDIENT_H
