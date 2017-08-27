cmake_minimum_required(VERSION 3.8)
project(BreakingBad)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        BrakingBad.cpp
        CorruptDeaAgent.h
        DeaAgent.h
        DrugDealer.h
        Location.h
        Person.h
        Provider.h)

add_executable(BreakingBad ${SOURCE_FILES})