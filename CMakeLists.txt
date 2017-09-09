cmake_minimum_required(VERSION 3.8)
project(BreakingBad)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        CorruptDeaAgent.h
        DeaAgent.h
        DrugDealer.h
        Location.h
        Person.h
        Provider.h Client.h Cook.h Distributor.h Meth.h Recipe.h Action.h Ingredient.h BreakingBad.h)

add_executable(BrakingBad ${SOURCE_FILES})