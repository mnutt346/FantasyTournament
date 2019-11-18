/**************************************************************************************
** Program name: medusa.cpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Implementation file for the Medusa class. The Medusa class
** inherits from the Character class.
**************************************************************************************/
#include <iostream>
#include "medusa.hpp"
#include "character.hpp"

using std::cout;
using std::endl;

/* Summary: Default constructor for Medusa class. Initializes the type, armor, and 
 * strength. Inherits from the Character base class.
 * Param: N/A
 * Return: N/A
 */
Medusa::Medusa() : Character("Medusa", 3, 8){};

/* Summary: Attack function for the Medusa class.
 * Param: Character *opponent -> pointer to the opponent's Character object
 * Param: int playerNum -> represents the attacking player
 * Return: int damage -> amount of damage dealt by the attack
 */
int Medusa::attack(Character *opponent, int playerNum)
{
    int damage = this->rollAttack(2, 6);

    if (damage == 12)
    {
        // use Glare
        cout << this->getName() << " has used Glare!" << endl
             << opponent->getName() << " is killed immediately!" << endl;

        damage = 100;

        return damage;
    }
    else
    {
        cout << this->getName() << " rolled an attack of " << damage << "!" << endl;

        return damage;
    }
}

/* Summary: Medusa's defend function
 * Param: int damage -> amount of damage to be defended
 * Param: int playerNum -> int value representing which player is defending
 * Return: N/A
 */
void Medusa::defend(int damage, int playerNum)
{
    // Get random roll
    int defense = this->rollDefense(1);

    cout << this->getName() << " rolled a defense of " << defense << "!" << endl;

    // Add player's armor to total defense
    defense += this->getArmor();

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