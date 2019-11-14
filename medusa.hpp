/**************************************************************************************
** Program name: medusa.hpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Declaration and header file for the Medusa class.
**************************************************************************************/
#include "character.hpp"

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

class Medusa : public Character
{
public:
    Medusa();
    int attack(Character *, int);
    void defend(int, int);
};

#endif