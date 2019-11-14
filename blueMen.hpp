/**************************************************************************************
** Program name: blueMen.hpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Declaration and header file for the BlueMen class.
**************************************************************************************/
#include "character.hpp"

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

class BlueMen : public Character
{
public:
    BlueMen();
    int attack(Character *, int);
    void defend(int, int);
};

#endif