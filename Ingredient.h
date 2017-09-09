//
// Created by vladimir khotyakov on 07/09/2017.
//

#ifndef BREAKINGBAD_INGREDIENT_H
#define BREAKINGBAD_INGREDIENT_H

class Ingredient{
protected:
    float price;
    int purity;
    int amount;

public:
    Ingredient(float price, int purity, int amount) : price(price), purity(purity), amount(amount) {
    }

    float getPrice() const {
        return price;
    }

    void setPrice(float price) {
        Ingredient::price = price;
    }

    int getPurity() const {
        return purity;
    }

    void setPurity(int purity) {
        Ingredient::purity = purity;
    }

    int getAmount() const {
        return amount;
    }

    void setAmount(int amount) {
        Ingredient::amount = amount;
    }
};

#endif //BREAKINGBAD_INGREDIENT_H
