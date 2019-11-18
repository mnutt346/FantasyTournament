/**************************************************************************************
** Program name: character.hpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Declaration and header file for the Character class.
**************************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class Character
{
protected:
    int maxStrength;
    std::string name;
    std::string type;
    int armor;
    int strength;
    bool dead;

public:
    Character(std::string, int, int);
    ~Character();
    std::string getName();
    void setName();
    std::string getType();
    int getArmor();
    int getStrength();
    void setStrength(int);
    virtual int attack(Character *, int) = 0;
    virtual void defend(int, int) = 0;
    void takeDamage(int);
    int rollAttack(int, int);
    int rollDefense(int);
    bool isDead();
    void printFightInfo(Character *);
    void restoreStrength();
};

#endif