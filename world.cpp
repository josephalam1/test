// Copyright [2021] <Joseph Alam>"
#include <iostream>
#include <vector>
#include "./World.h"
using std::vector;
using std::endl;


void World::initGrid() {
    std::cout << "Hola";
}

void World::PrintGrid() {
    std::cout << "World at Day " << day << endl;
    std::cout << " ---+---+---+---+---+---+---+--- " << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "| ";
        for (int j = 0; j < 10; j++) {
            std::cout << grid[i][j] <<  " | ";
        }
        std::cout << std::endl;
        std::cout << " ---+---+---+---+---+---+---+--- " << std::endl;
    }
}
