// Copyright [2021] <Joseph Alam>"
#ifndef HUMAN_H_
#define HUMAN_H_
#include <iostream>
#include <string>
class Human {
     public:
        Human();
        void move();
        std::string toString() const;
        int xPos, yPos, age;
        bool male;
        float immunity = 1.0;
};

#endif    //   HUMAN_H_
