#include <iostream>
#include <string>
#include <vector>
#include "game.hpp"
#include "menu.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"
#include "blueMen.hpp"
#include "medusa.hpp"
#include "harryPotter.hpp"
#include "characterQueue.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/* Summary: Game default constructor
 * Param: N/A
 * Return: N/A
 */
Game::Game()
{
    int round = 1;
}

/* Summary: Driver for the game and provides an interface for the user
 * Param: N/A
 * Return: N/A
 */
void Game::playGame()
{
    const string TITLE = "Fantasy Combat Game";

    cout << endl
         << "----- Welcome to Fantasy Combat! -----" << endl;

    bool programSelection = startMenu(TITLE);
    if (!programSelection)
    {
        cout << "Exiting program..." << endl;
        //deallocateMem();
        exit(0);
    }

    while (programSelection)
    {
        cout << "Each player must choose 5 characters for their team." << endl;
        // Prompt player 1 to pick his/her team
        pickTeams(1);
        // Prompt player 2 to pick his/her team
        pickTeams(2);

        currentRound = 1;

        // do
        // {
        //     cout << "___________________________________________________________" << endl
        //          << "Round " << currentRound << "!" << endl
        //          << "Player 1 has " << player1->getStrength() << " strength points remaining." << endl
        //          << "Player 2 has " << player2->getStrength() << " strength points remaining." << endl
        //          << "__________________________________________________________" << endl
        //          << endl;

        //     fight();

        //     currentRound++;

        //     cout << endl
        //          << "Press enter continue." << endl;
        //     cin.get();
        // } while (allAlive());

        //deallocateMem();

        programSelection = startMenu(TITLE);
    }
}

void Game::pickTeams(int player)
{
    bool isPlayerOne = (player == 1);

    for (int i = 0; i < TEAM_SIZE; i++)
    {
        int playerSelection = promptPlayerSelection(player);
        string playerName = setPlayer(player1Characters, playerSelection);
        cout << "Player " << (player == 1 ? "One" : "Two") << " has added " << playerName << " to their team!";
    }
}

/* Summary: Prompts the player to select a character
 * Param: int player -> represents which player is choosing a character
 * Return: Returns an integer representing the players character choice
 */
int Game::promptPlayerSelection(int player)
{
    int playerSelection;

    const string CHARACTER_TYPE_1 = "Vampire";
    const string CHARACTER_TYPE_2 = "Barbarian";
    const string CHARACTER_TYPE_3 = "Blue Men";
    const string CHARACTER_TYPE_4 = "Medusa";
    const string CHARACTER_TYPE_5 = "Harry Potter";

    vector<string> characters{CHARACTER_TYPE_1, CHARACTER_TYPE_2, CHARACTER_TYPE_3, CHARACTER_TYPE_4, CHARACTER_TYPE_5};

    bool isPlayer1 = (player == 1);

    cout << endl
         << endl
         << "Player " << (isPlayer1 ? "One" : "Two") << ", choose a character." << endl;

    playerSelection = multiOptionMenu(characters);

    return playerSelection;
}

/* Summary: Sets the player's character type
 * Param: Character *&player -> reference to a Character pointer
 * Param: playerSelection -> the character selected by the user
 * Return: Returns a string value representing the character type chosen by the user
 */
string Game::setPlayer(CharacterQueue &playerCharacters, int playerSelection)
{
    string characterName;
    Character *newCharacter;

    switch (playerSelection)
    {
    case 1:
    {
        newCharacter = new Vampire;
        newCharacter->setName();
        playerCharacters.addToEnd(newCharacter);
        break;
    }
    case 2:
    {
        newCharacter = new Barbarian;
        newCharacter->setName();
        playerCharacters.addToEnd(newCharacter);
        break;
    }
    case 3:
    {
        newCharacter = new BlueMen;
        newCharacter->setName();
        playerCharacters.addToEnd(newCharacter);
        break;
    }
    case 4:
    {
        newCharacter = new Medusa;
        newCharacter->setName();
        playerCharacters.addToEnd(newCharacter);
        break;
    }
    case 5:
    {
        newCharacter = new HarryPotter;
        newCharacter->setName();
        playerCharacters.addToEnd(newCharacter);
        break;
    }
    default:
        break;
    }

    characterName = newCharacter->getName();
    return characterName;
}

/* Summary: Determines whether both players have characters remaining on their teams
 * Param: N/A
 * Return: Returns a boolean value representing whether both players have characters remaining
 */
bool Game::allAlive()
{
    if (player1Characters.isEmpty() || player2Characters.isEmpty())
    {
        return false;
    }

    return true;
}

/* Summary: Handles the combat for each round
 * Param: N/A
 * Return: N/A
 */

/* void Game::fight()
{
    cout << "Player 1 is the attacker!" << endl;
    player1->printFightInfo(player2);
    // Get player 1's attack damage
    int attack1Damage = player1->attack(player2, 1);
    // Player 2 defends against player 1's attack
    player2->defend(attack1Damage, 2);

    // If player 2 died after the initial attack
    if (player2->isDead())
    {
        cout << endl
             << "***** Player 2 has died! Player 1 wins! *****" << endl;
    }
    // If player 2 is still alive
    else
    {
        // Player 2 is the attacker
        cout << endl
             << "Player 2 is now the attacker!" << endl;
        player2->printFightInfo(player1);
        // Get player 2's attack damage
        int attack2Damage = player2->attack(player1, 2);
        // Player 1 defends against player 2's attack
        player1->defend(attack2Damage, 1);

        // If player 1 dies
        if (player1->isDead())
        {
            cout << endl
                 << "***** Player 1 has died! Player 2 wins! *****" << endl;
        }
    }
}
*/
/* Summary: Deallocates memory used by the two characters
 * Param: N/A
 * Return: N/A
 */
/*
void Game::deallocateMem()
{
    delete player1;
    delete player2;
}

*/
