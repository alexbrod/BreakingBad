//
// Created by vladimir khotyakov on 06/09/2017.
//

#ifndef _COOK_H
#define _COOK_H

class Distributor;
class Cook: public DrugDealer
{
    Provider** provider;
    Distributor** distributor;
    Meth meth;
    Recipe* recipe;
    int fee;
public:
    Cook(int id, char* name = NULL, float balance = 0, int fee = 0):
            Person(id, name, balance), DrugDealer(id, name, balance){cout << "Cook::Cook\n";}
    Cook(const Cook& p) = delete;
    ~Cook(){cout << "Cook::~Cook\n";}
    //getters and setters
    Provider **getProvider() const {
        return provider;
    }

    void setProvider(Provider **provider) {
        Cook::provider = provider;
    }

    Distributor **getDistributor() const {
        return distributor;
    }

    void setDistributor(Distributor **distributor) {
        Cook::distributor = distributor;
    }

    const Meth &getMeth() const {
        return meth;
    }

    void setMeth(const Meth &meth) {
        Cook::meth = meth;
    }

    Recipe *getRecipe() const {
        return recipe;
    }

    void setRecipe(Recipe *recipe) {
        Cook::recipe = recipe;
    }

    int getFee() const {
        return fee;
    }

    void setFee(int fee) {
        Cook::fee = fee;
    }
    //methods

    virtual //operators
    bool operator==(const Cook &rhs) const{}

    bool operator!=(const Cook &rhs) const {
        return !(rhs == *this);
    }
};

#endif //BREAKINGBAD_COOK_H
