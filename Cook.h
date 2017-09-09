//
// Created by vladimir khotyakov on 06/09/2017.
//

#ifndef _COOCK_H
#define _COOCK_H



class Cook: public DrugDealer {

protected:
    Recipe* recipe;
    Meth* meth;

public:
    Cook(int id, const char *name, int balance) :
            Person(id, const_cast<char *>(name), balance), DrugDealer(id, const_cast<char *>(name), balance){cout << "Distributor::Distributor\n";}

    void setRecepie(Recipe *pRecipe) ;

    Recipe *getRecipe() const {
        return recipe;
    }

    void setRecipe(Recipe *recipe) {
        Cook::recipe = recipe;
    }

    Meth *getMeth() const {
        return meth;
    }

    void setMeth(Meth *meth) {
        Cook::meth = meth;
    }

    virtual bool operator==(const Cook &rhs)  const =0 ;

    virtual bool operator!=(const Cook &rhs)  const =0;

};



#endif //BREAKINGBAD_COOCK_H
