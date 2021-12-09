// Copyright [2021] <Joseph Alam>"
#include "./virus.h"
Virus::Virus() {
    xPos = std::rand() % 10;
    yPos = std::rand() % 10;
}
void Virus::move() {
    int r1 = std::rand() % 3 - 1;
    int r2 = std::rand() % 3 - 1;
    if (   this->xPos + r1 < 10 && this->xPos + r1 >= 0
        && this->yPos + r2 < 10 && this->yPos + r2 >= 0) {
        this->xPos += r1;
        this->yPos += r2;
    }
}
std::string Virus::toString() {
    return "🦠";
}
