//
// Created by vladimir khotyakov on 09/09/2017.
//

#ifndef BREAKINGBAD_BREAKINGBAD_H
#define BREAKINGBAD_BREAKINGBAD_H

class BreakingBad{

public:
    Ingredient **initIngBreakingBadredients(const char** ingredientNames, const int i);

    Action **initActions(const char **actionNAmes, const int amount) ;

    Ingredient **initIngredients(const char **ingridNames, const int amount) ;

    Recipe *createRecepie(Action **pAction, Ingredient **pIngredient) ;

    void addPersons(Person **pPerson) ;

    void addLocations(Location **pLocation) ;

    void assignProvidersToCooks() ;

    void assignDistributorsToCooks() ;

    bool endOfGame() ;

    void allocatePersonsToNewLocations() ;

    void workForThisTurn();

    void showPersonsStats();

    void showWhoWon();
};

#endif //BREAKINGBAD_BREAKINGBAD_H
