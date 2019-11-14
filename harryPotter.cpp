/**************************************************************************************
** Program name: harryPotter.cpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Implementation file for the HarryPotter class. The HarryPotter class
** inherits from the Character class.
**************************************************************************************/
#include <iostream>
#include "harryPotter.hpp"
#include "character.hpp"

using std::cout;
using std::endl;

/* Summary: HarryPotter default constructor initializes a new Character with the given type
 * and armor of 0 and strength of 10
 * Param: N/A
 * Return: N/A
 */
HarryPotter::HarryPotter() : Character("Harry Potter", 0, 10){};

/* Summary: HarryPotter's attack function
 * Param: Character *opponent -> pointer to the opponent's Character
 * Param: int playerNum -> int value representing which player is attacking
 * Return: Returns an int representing the amount of damage dealt
 */
int HarryPotter::attack(Character *opponent, int playerNum)
{
    int damage = this->rollAttack(2, 6);

    cout << (playerNum == 1 ? "Player 1" : "Player 2") << " rolled an attack of " << damage << "!" << endl;

    return damage;
}

/* Summary: HarryPotter's defend function
 * Param: int damage -> amount of damage to be defended
 * Param: int playerNum -> int value representing which player is defending
 * Return: N/A
 */
void HarryPotter::defend(int damage, int playerNum)
{
    // Get random roll
    int defense = this->rollDefense(2);

    bool hogwartsActive = this->getHogwarts();

    cout << (playerNum == 1 ? "Player 1" : "Player 2") << " rolled a defense of " << defense << "!" << endl;

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

        if (this->getStrength() <= 0 && hogwartsActive)
        {
            this->setStrength(20);

            cout << (playerNum == 1 ? "Player 1" : "Player 2") << " used Hogwarts!" << endl
                 << (playerNum == 1 ? "Player 1" : "Player 2") << " has returned to fight again!" << endl;

            this->setHogwarts();
        }

        cout << (playerNum == 1 ? "Player 1" : "Player 2") << "'s current strength is now " << this->getStrength() << "." << endl;
    }
}

/* Summary: Gets the current value of the hogwarts property
 * Param: N/A
 * Return: Returns a boolean value determining whether the Hogwarts ability has been used
 */
bool HarryPotter::getHogwarts()
{
    return hogwarts;
}

/* Summary: Sets the value of the hogwarts property to false once the ability is used
 * Param: N/A
 * Return: N/A
 */
void HarryPotter::setHogwarts()
{
    hogwarts = false;
}