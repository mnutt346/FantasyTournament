/**************************************************************************************
** Program name: vampire.cpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Implementation file for the Vampire class. The Vampire class
** inherits from the Character class.
**************************************************************************************/
#include <iostream>
#include "vampire.hpp"
#include "character.hpp"
#include "randomNum.hpp"

using std::cout;
using std::endl;

/* Summary: Default constructor for Vampire class. Initializes the type, armor, and 
 * strength. Inherits from the Character base class.
 * Param: N/A
 * Return: N/A
 */
Vampire::Vampire() : Character("Vampire", 1, 18){};

/* Summary: Attack function for the Vampire class.
 * Param: Character *opponent -> pointer to the opponent's Character object
 * Param: int playerNum -> represents the attacking player
 * Return: int damage -> amount of damage dealt by the attack
 */
int Vampire::attack(Character *opponent, int playerNum)
{
    int damage = this->rollAttack(1, 12);

    cout << this->getName() << " rolled an attack of " << damage << "!" << endl;

    return damage;
};

/* Summary: Defend function for the Vampire class. Untilizes the "Charm" ability
 * Param: int damage -> represents the amount of damage dealt to the defender
 * Param: int playerNum -> represents the defending player
 * Return: N/A
 */
void Vampire::defend(int damage, int playerNum)
{
    int charm = randomNum(1, 2);

    // If the player used "Charm"
    if (charm == 1)
    {
        cout << this->getName() << " used Charm! No damage was taken!" << endl;
    }
    else
    {
        // Get random roll
        int defense = this->rollDefense(1);

        cout << this->getName() << " rolled a defense of " << defense << "!" << endl;

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
}