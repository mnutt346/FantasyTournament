/**************************************************************************************
** Program name: blueMen.cpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Implementation file for the BlueMen class. The BlueMen class
** inherits from the Character class.
**************************************************************************************/
#include <iostream>
#include "blueMen.hpp"
#include "character.hpp"

using std::cout;
using std::endl;

/* Summary: Default constructor for BlueMen class. Initializes the type, armor, and 
 * strength. Inherits from the Character base class.
 * Param: N/A
 * Return: N/A
 */
BlueMen::BlueMen() : Character("Blue Men", 3, 12){};

/* Summary: Attack function for the BlueMen class.
 * Param: Character *opponent -> pointer to the opponent's Character object
 * Param: int playerNum -> represents the attacking player
 * Return: int damage -> amount of damage dealt by the attack
 */
int BlueMen::attack(Character *opponent, int playerNum)
{
    int damage = this->rollAttack(2, 10);

    cout << (playerNum == 1 ? "Player 1" : "Player 2") << " rolled an attack of " << damage << "!" << endl;

    return damage;
}

/* Summary: Defend function for the BlueMen class.
 * Param: int damage -> represents the amount of damage dealt to the defender
 * Param: int playerNum -> represents the defending player
 * Return: N/A
 */
void BlueMen::defend(int damage, int playerNum)
{
    int currentStrength = this->getStrength();
    int defense = 0;

    // If the player has taken less than 4 points of damage
    if (currentStrength <= 12 && currentStrength > 8)
    {
        // use 3 dice
        defense = this->rollDefense(3);
    }
    // If the player has taken between 4 and 7 points of damage
    else if (currentStrength <= 8 && currentStrength > 4)
    {
        // use 2 dice
        defense = this->rollDefense(2);
    }
    else
    {
        // use 1 die
        defense = this->rollDefense(1);
    }

    cout << (playerNum == 1 ? "Player 1" : "Player 2") << " rolled a defense of " << defense << "!" << endl;

    // add the player's armor to the total defense score
    defense += this->getArmor();

    // If the defense roll is greater than the damage dealt
    if (defense >= damage)
    {
        cout << "No damage was inflicted on " << (playerNum == 1 ? "Player 1" : "Player 2") << "." << endl;
    }
    else
    {
        int inflictedDamage = damage - defense;

        cout << (playerNum == 1 ? "Player 1" : "Player 2") << " took damage of " << inflictedDamage << "!" << endl;

        // Reduce player's strength by the actual damage inflicted
        this->takeDamage(inflictedDamage);

        cout << (playerNum == 1 ? "Player 1" : "Player 2") << "'s current strength is now " << this->getStrength() << "." << endl;
    }
}