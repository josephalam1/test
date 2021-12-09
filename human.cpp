// Copyright [2021] <Joseph Alam>"
#include "./Human.h"
Human::Human() {
    age = 0;
    xPos = std::rand() % 10;
    yPos = std::rand() % 10;
    if (std::rand() % 2 == 0) {
        male = true;
    } else {
        male = false;
    }
}
void Human::move() {
    this->age++;
    int r1 = std::rand() % 3 - 1;
    int r2 = std::rand() % 3 - 1;
    if (   this->xPos + r1 < 10 && this->xPos + r1 >= 0
        && this->yPos + r2 < 10 && this->yPos + r2 >= 0) {
        this->xPos += r1;
        this->yPos += r2;
    }
}
std::string Human::toString() const {
    if (age > 5 && age < 18) {
        if (male)
            return "👦";
        else
            return "👧";
    }
    if (age >= 18 && age < 60) {
        if (male)
            return "👨";
        else
            return "👩";
    }
    if (age > 60) {
        if (male)
            return "👴";
        else
            return "👵";
    }
    return "👶";
}
