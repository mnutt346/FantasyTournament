/**************************************************************************************
** Program name: character.cpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Implementation file for the Character class.
**************************************************************************************/
#include <iostream>
#include <string>
#include <cmath>
#include "character.hpp"
#include "randomNum.hpp"
#include "inputValidation.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::floor;
using std::string;

/* Summary: Constructor for the Character class. Initializes the type, armor, and strength.
 * Param: string characterType -> type of character
 * Param: int arm -> armor
 * Param: int stren -> strength
 * Return: N/A
 */
Character::Character(string characterType, int arm, int stren)
{
    this->maxStrength = stren;
    this->type = characterType;
    this->armor = arm;
    this->strength = stren;
    this->dead = false;
}

/* Summary: Gets the Character's name
 * Param: N/A
 * Return: Returns a string representing the Character's name
 */
string Character::getName()
{
    return name;
}

void Character::setName()
{
    string userName;

    cout << endl
         << "Please input a name for your character no greater than 50 characters long:" << endl;

    getline(cin, userName);

    while (!isAlphaNumInput(userName))
    {
        cout << endl
             << "Please enter only alpha-numeric characters with a length no greater than 50." << endl;

        getline(cin, userName);
    }

    this->name = userName;
}

/* Summary: Gets the Character's type
 * Param: N/A
 * Return: Returns a string representing the Character's type
 */
string Character::getType()
{
    return type;
}

/* Summary: Gets the Character's armor point value
 * Param: N/A
 * Return: Returns an int representing the Character's armor point value
 */
int Character::getArmor()
{
    return armor;
}

/* Summary: Gets the Character's strength point value
 * Param: N/A
 * Return: Returns an int representing the Character's strength point value
 */
int Character::getStrength()
{
    return strength;
}

/* Summary: Sets the Character's armor point value
 * Param: N/A
 * Return: N/A
 */
void Character::setStrength(int newStrength)
{
    strength = newStrength;
}

/* Summary: Reduces the Character's strength by the amount passed in
 * Param: int damage -> the amount of damage dealt to the Character
 * Return: N/A
 */
void Character::takeDamage(int damage)
{
    strength -= damage;
}

/* Summary: Provides a random number based on the number of dice and total sides per attack die
 * Param: N/A
 * Return: Returns an int representing the Character's attack roll
 */
int Character::rollAttack(int dieCount, int dieSides)
{
    int attackTotal = 0;

    for (int i = 0; i < dieCount; i++)
    {
        attackTotal += randomNum(1, dieSides);
    }

    return attackTotal;
}

/* Summary: Provides a random number based on the number of dice and total sides per defense die
 * Param: N/A
 * Return: Returns an int representing the Character's defense roll
 */
int Character::rollDefense(int dieCount)
{
    int defenseTotal = 0;

    for (int i = 0; i < dieCount; i++)
    {
        defenseTotal += randomNum(1, 6);
    }

    return defenseTotal;
}

/* Summary: Determines whether a Character is dead
 * Param: N/A
 * Return: Returns a boolean value: true if the Character is dead, false if they are alive
 */
bool Character::isDead()
{
    if (this->strength <= 0)
    {
        this->dead = true;
    }

    return dead;
}

/* Summary: Prints the attacker and defender type at the start of each round
 * Param: Character *opponent -> pointer to the attacking player's opponent
 * Return: N/A
 */
void Character::printFightInfo(Character *opponent)
{
    cout << "Attacker Type: " << this->getType() << endl
         << "Defender Type: " << opponent->getType() << ", Armor: " << opponent->getArmor() << ", Strength: " << opponent->getStrength() << endl;
}

/* Summary: Restores 50% of the strength lost by the character in combat
 * Param: N/A
 * Return: N/A
 */
void Character::restoreStrength()
{
    const double RESTORE_PERCENT = 0.5;

    int damageTaken = maxStrength - strength;

    int strengthReturned = floor(damageTaken * RESTORE_PERCENT);

    this->setStrength((strength + strengthReturned));
}