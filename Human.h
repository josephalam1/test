// Copyright [2021] <Joseph Alam>"
#ifndef HUMAN_H_
#define HUMAN_H_
#include <iostream>
#include <string>
#include <vector>
using std::vector;
class Human {
     public:
        Human();
        bool operator==(const Human human);
        void move();
        std::string toString();
        int xPos, yPos, age;
        bool male;
        float immunity = 1.0;
};

#endif    //   HUMAN_H_
