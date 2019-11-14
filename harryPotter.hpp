/**************************************************************************************
** Program name: harryPotter.hpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Declaration and header file for the HarryPotter class.
**************************************************************************************/
#include "character.hpp"

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

class HarryPotter : public Character
{
private:
    bool hogwarts = true;

public:
    HarryPotter();
    void setHogwarts();
    bool getHogwarts();
    int attack(Character *, int);
    void defend(int, int);
};

#endif