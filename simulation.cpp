// Copyright [2021] <Joseph Alam>"
#include "./simulation.h"
Simulation::Simulation() {
    day = 0;
    std::srand(time(0));
    this->initGrid();
}
void Simulation::PrintGrid() {
    resetGrid();
    for (Virus virus : viruses) {
        grid[virus.yPos][virus.xPos] = virus.toString();
    }
    for (Human human : players) {
        grid[human.yPos][human.xPos] = human.toString();
        std::cout << "Displaying player at: " << human.xPos << ", " << human.yPos << "\n";

    }
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
    for (int i = 0; i < 10; i++) {
        Human human;
        human.age = std::rand() % 65;
        players.push_back(human);
    }
    Virus virus;
    viruses.push_back(virus);
    UpdateGrid();
}
void Simulation::UpdateGrid() {
    resetGrid();
    while (day < 10) {
        day++;
        if (day % 10 == 0) {
            Virus virus;
            viruses.push_back(virus);
        }
        if (day % 50 == 0) {
            viruses.erase(viruses.begin());
        }
        for (Virus virus : viruses) {
            virus.move();
        }
        for (Human human : players) {
std::cout << "-Player previous position: " << human.xPos << ", " << human.yPos << "\n";
            human.move();
std::cout << "-Player current position: " << human.xPos << ", " << human.yPos << "\n";
        }
        checkPlayerColisions();
        checkVirusColisions();
        PrintGrid();
        if (checkFull() || players.size() == 0) break;
    }
    if (players.size() <= 0) {
        std::cout <<
        "\nThe last remaining human passed away on day " << day + 1 << "\n";
    }
}
void Simulation::checkPlayerColisions() {
    for (int i = 0; i < players.size(); i++) {
        for (int j = i + 1; j < players.size(); j++) {
            if (players[i] == players[j]) {
                std::cout << "TWO PLAYERS FUCKING COLLIDED\n\n\n\n\n\n";
                Human human;
                players.push_back(human);
            }
        }
    }
}
void Simulation::checkVirusColisions() {
    for (Virus virus : viruses) {
        for (int i = 0; i < players.size(); i++) {
            if (virus.xPos == players[i].xPos
             && virus.yPos == players[i].yPos) {
                 if (players[i].age < 3 || players[i].age >= 60
                 || players[i].immunity <= 0.25) {
                    players.erase(players.begin() + i);
                 } else {
                    players[i].immunity -=
                static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
                }
            }
        }
    }
}

bool Simulation::checkFull() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (grid[i][j] == "  ") return false;
        }
    }
    return true;
}
