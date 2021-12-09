// Copyright [2021] <Joseph Alam>"
#ifndef VIRUS_H_
#define VIRUS_H_
#include <iostream>
#include <string>
class Virus {
     public:
        Virus();
        void move();
        std::string toString();
        int xPos, yPos;
};

#endif    //   VIRUS_H_🗡
