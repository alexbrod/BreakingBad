//
// Created by vladimir khotyakov on 07/09/2017.
//

#ifndef BREAKINGBAD_INGREDIENT_H
#define BREAKINGBAD_INGREDIENT_H

#include <ostream>

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

    bool operator<(const Ingredient &rhs) const {
        if (price < rhs.price)
            return true;
        if (rhs.price < price)
            return false;
        if (purity < rhs.purity)
            return true;
        if (rhs.purity < purity)
            return false;
        return amount < rhs.amount;
    }

    bool operator>(const Ingredient &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Ingredient &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Ingredient &rhs) const {
        return !(*this < rhs);
    }

    friend ostream &operator<<(ostream &os, const Ingredient &ingredient) {
        os << "price: " << ingredient.price << " purity: " << ingredient.purity << " amount: " << ingredient.amount;
        return os;
    }
};

#endif //BREAKINGBAD_INGREDIENT_H
