/**************************************************************************************
** Program name: vampire.hpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Declaration and header file for the Vampire class.
**************************************************************************************/
#ifndef VAMPIRE_HPP
#define vAMPIRE_HPP

#include "character.hpp"

class Vampire : public Character
{
public:
    Vampire();
    int attack(Character *, int);
    void defend(int, int);
};

#endif