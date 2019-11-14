/**************************************************************************************
** Program name: barbarian.hpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Declaration and header file for the Barbarian class.
**************************************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "character.hpp"

class Barbarian : public Character
{
public:
    Barbarian();
    int attack(Character *, int);
    void defend(int, int);
};

#endif