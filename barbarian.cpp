/**************************************************************************************
** Program name: barbarian.cpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Implementation file for the Barbarian class. The Barbarian class
** inherits from the Character class.
**************************************************************************************/
#include <iostream>
#include "barbarian.hpp"
#include "character.hpp"

using std::cout;
using std::endl;

/* Summary: Default constructor for Barbarian class. Initializes the type, armor, and 
 * strength. Inherits from the Character base class.
 * Param: N/A
 * Return: N/A
 */
Barbarian::Barbarian() : Character("Barbarian", 0, 12){};

/* Summary: Attack function for the Barbarian class.
 * Param: Character *opponent -> pointer to the opponent's Character object
 * Param: int playerNum -> represents the attacking player
 * Return: int damage -> amount of damage dealt by the attack
 */
int Barbarian::attack(Character *opponent, int playerNum)
{
    int damage = this->rollAttack(2, 6);

    cout << this->getName() << " rolled an attack of " << damage << "!" << endl;

    return damage;
};

/* Summary: Defend function for the Barbarian class.
 * Param: int damage -> represents the amount of damage dealt to the defender
 * Param: int playerNum -> represents the defending player
 * Return: N/A
 */
void Barbarian::defend(int damage, int playerNum)
{
    // Get random roll
    int defense = this->rollDefense(2);

    cout << this->getName() << " rolled a defense of " << defense << "!" << endl;

    // If the defense roll is greater than the damage dealt
    if (defense >= damage)
    {
        cout << "No damage was inflicted on " << this->getName() << "." << endl;
    }
    else
    {
        int inflictedDamage = damage - defense;

        cout << this->getName() << " took damage of " << inflictedDamage << "!" << endl;

        // Reduce player's strength by the actual damage inflicted
        this->takeDamage(inflictedDamage);

        cout << this->getName() << "'s current strength is now " << this->getStrength() << "." << endl;
    }
}