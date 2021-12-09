// Copyright [2021] <Joseph Alam>"
#include "./simulation.h"
Simulation::Simulation() {
    day = 0;
    this->initGrid();
    std::srand(time(0));
}
void Simulation::PrintGrid() {
    std::cout << "World at Day " << day <<
    "             # of people left: " << players.size() << endl;
    std::cout <<
    " -------------------------------------------------" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "| ";
        for (int j = 0; j < 10; j++) {
            std::cout << grid[i][j] <<  " | ";
        }
        std::cout << std::endl;
        std::cout <<
        "+-------------------------------------------------+" << std::endl;
    }
}
void Simulation::resetGrid() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j] = "  ";
        }
    }
}
void Simulation::initGrid() {
    resetGrid();
    for (int i = 0; i < 10; i++) {
        Human human;
        human.age = std::rand() % 65;
        players.push_back(human);
        grid[human.xPos][human.yPos] = human.toString();
    }
    Virus virus;
    viruses.push_back(virus);
    grid[virus.xPos][virus.yPos] = virus.toString();
    this->PrintGrid();
    this->UpdateGrid();
}
void Simulation::UpdateGrid() {
    while(day < 7000) {
        day += 1;
        if (day % 10 == 0) {
            Virus virus;
            viruses.push_back(virus);
        }
        resetGrid();
        for (Virus virus : viruses) {
            virus.move();
            grid[virus.xPos][virus.yPos] = virus.toString();
        }
        for (Human human : players) {
            human.move();
            grid[human.xPos][human.yPos] = human.toString();
        }
        checkPlayerColisions();
        checkVirusColisions();
        this->PrintGrid();
        if (checkFull()) break;
    }
}
void Simulation::checkPlayerColisions() {
    for (int i = 0; i < players.size(); i++) {
        for (int j = i + 1; j < players.size(); j++) {
            if (players[i].xPos == players[j].xPos
             && players[i].yPos == players[j].yPos
             && players[i].male != players[j].male
             && players[i].age >= 18 && players[j].age >= 18) {
                 Human human;
                players.push_back(human);
                // players.insert(players.begin(), human);
            }
        }
    }
}
void Simulation::checkVirusColisions() {
    for (Virus virus : viruses) {
        for (int i = 0; i < players.size(); i++) {
            if (virus.xPos == players[i].xPos
             && virus.yPos == players[i].yPos) {
                 if (players[i].age < 4 || players[i].age >= 60
                 || players[i].immunity <= 0.25) {
                    players.erase(players.begin() + i);
                 } else {
                    float amount = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
                    players[i].immunity -= amount;
                }
            }
        }
    }
}

bool Simulation::checkFull() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == "  ")
                return false;
        }
    }
    return true;
}
