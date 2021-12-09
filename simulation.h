// Copyright [2021] <Joseph Alam>"
#ifndef SIMULATION_H_
#define SIMULATION_H_
#include <iostream>
#include <vector>
#include <ctime>
#include "./World.h"
#include "./human.cpp"
#include "./virus.cpp"
using std::vector;
using std::endl;
class Simulation: public World {
    public :
        vector<Human> players;
        vector<Virus> viruses;
        Simulation();
        void PrintGrid();
        void UpdateGrid();
    protected :
        void initGrid();
        void checkPlayerColisions();
        void checkVirusColisions();
        bool checkFull();
        void resetGrid();
        
};

#endif    //   SIMULATION_H_
