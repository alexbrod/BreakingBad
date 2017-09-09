//
// Created by vladimir khotyakov on 06/09/2017.
//

#ifndef _COOCK_H
#define _COOCK_H

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
    bool operator==(const Cook &rhs) const = 0 ;

    bool operator!=(const Cook &rhs) const {
        return !(rhs == *this);
    }
};

//class Cook: public DrugDealer {
//
//protected:
//    Recipe* recipe;
//    Meth* meth;
//
//public:
//    Cook(int id, const char *name, int balance) :
//            Person(id, const_cast<char *>(name), balance), DrugDealer(id, const_cast<char *>(name), balance){cout << "Distributor::Distributor\n";}
//
//    void setRecepie(Recipe *pRecipe) ;
//
//    Recipe *getRecipe() const {
//        return recipe;
//    }
//
//    void setRecipe(Recipe *recipe) {
//        Cook::recipe = recipe;
//    }
//
//    Meth *getMeth() const {
//        return meth;
//    }
//
//    void setMeth(Meth *meth) {
//        Cook::meth = meth;
//    }
//
//    virtual bool operator==(const Cook &rhs)  const =0 ;
//
//    virtual bool operator!=(const Cook &rhs)  const =0;
//
//};



#endif //BREAKINGBAD_COOCK_H
