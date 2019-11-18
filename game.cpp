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
    player1Score = 0;
    player2Score = 0;
}

/* Summary: Driver for the game and provides an interface for the user
 * Param: N/A
 * Return: N/A
 */
void Game::playGame()
{
    const string TITLE = "Fantasy Combat Game";
    vector<string> losingCharacterOptions = {"Yes", "No"};

    cout << endl
         << "----- Welcome to Fantasy Combat! -----" << endl;

    bool programSelection = startMenu(TITLE);
    if (!programSelection)
    {
        cout << "Exiting program..." << endl;
        deallocateMem();
        exit(0);
    }

    while (programSelection)
    {
        cout << endl
             << "Each player must choose 5 characters for their team." << endl;
        // Prompt player 1 to pick his/her team
        pickTeams(1);
        // Prompt player 2 to pick his/her team
        pickTeams(2);

        do
        {
            runTournament();

        } while (allAlive());

        // Print final score
        printScore();

        // Prompt user to view loosers queue
        cout << endl
             << "Would you like to view the losing characters?";
        int viewLosersSelection = multiOptionMenu(losingCharacterOptions);

        handleLosersSelection(viewLosersSelection);

        // Clear all characters from both teams
        clearTeams();
        // Reset scores to 0
        player1Score = 0;
        player2Score = 0;

        programSelection = startMenu(TITLE);
    }
    deallocateMem();
    exit(0);
}

void Game::pickTeams(int player)
{
    bool isPlayerOne = (player == 1);

    for (int i = 0; i < TEAM_SIZE; i++)
    {
        int playerSelection = promptPlayerSelection(player);
        string playerName = (player == 1 ? (setPlayer(player1Characters, playerSelection)) : (setPlayer(player2Characters, playerSelection)));
        cout << "Player " << (player == 1 ? "One" : "Two") << " has added " << playerName << " to their team!" << endl;
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
    // If either player is out of characters:
    if (player1Characters.isEmpty() || player2Characters.isEmpty())
    {
        return false;
    }

    return true;
}

/* Summary: Determines whether each player's character is alive
 * Param: Character *player1 => pointer to Player 1's current character
 * Param: Character *player2 => pointer to Player 2's current character
 * Return: Returns a boolean value representing whether both players' characters are alive
 */
bool Game::bothAlive(Character *&player1, Character *&player2)
{
    // If either player is dead:
    if (player1->isDead() || player2->isDead())
    {
        return false;
    }

    return true;
}

/* Summary: Handles the combat for each round
 * Param: N/A
 * Return: N/A
 */

void Game::fight(Character *player1, Character *player2)
{
    cout << player1->getName() << " is the attacker!" << endl;
    player1->printFightInfo(player2);
    // Get player 1's attack damage
    int attack1Damage = player1->attack(player2, 1);
    // Player 2 defends against player 1's attack
    player2->defend(attack1Damage, 2);

    // If player 2 died after the initial attack
    if (player2->isDead())
    {
        // Add Player 2's current character to the losers queue
        losers.addToEnd(player2);
        // Remove Player 2's current character from the characters queue
        player2Characters.removeHead();

        // Replenish Player 1 character's strength
        player1->restoreStrength();
        // Move Player 1's character to end of queue
        player1Characters.moveHeadToEnd();
        // Increase Player 1's score
        player1Score++;

        cout << endl
             << "***** " << player2->getName() << " has died! " << player1->getName() << " wins! *****" << endl;
    }
    // If player 2 is still alive
    else
    {
        // Player 2 is the attacker
        cout << endl
             << player2->getName() << " is now the attacker!" << endl;
        player2->printFightInfo(player1);
        // Get player 2's attack damage
        int attack2Damage = player2->attack(player1, 2);
        // Player 1 defends against player 2's attack
        player1->defend(attack2Damage, 1);

        // If player 1 dies
        if (player1->isDead())
        {
            // Add Player 1's current character to the losers queue
            losers.addToEnd(player1);
            // Remove Player 1's current character from the characters queue
            player1Characters.removeHead();

            // Replenish Player 2 character's strength
            player2->restoreStrength();
            // Move Player 2's character to end of queue
            player2Characters.moveHeadToEnd();
            // Increase Player 2's score
            player2Score++;

            cout << endl
                 << "***** " << player1->getName() << " has died! " << player2->getName() << " wins! *****" << endl;
        }
    }
}

/* Summary: Deallocates memory used by the two characters
 * Param: N/A
 * Return: N/A
 */

void Game::deallocateMem()
{
    player1Characters.deallocateMem();
    player2Characters.deallocateMem();
}

void Game::runTournament()
{
    int currentRound = 1;
    // Get Player 1's current character
    CharacterNode *player1Front = player1Characters.getHead();
    Character *player1Current = player1Front->character;
    // Get Player 2's current character
    CharacterNode *player2Front = player2Characters.getHead();
    Character *player2Current = player2Front->character;

    do
    {
        cout << "___________________________________________________________" << endl
             << "Round " << currentRound << "!" << endl
             << "Player 1's current character: " << player1Current->getName() << endl
             << "Player 2's current character: " << player2Current->getName() << endl
             << player1Current->getName() << " has " << player1Current->getStrength() << " strength points remaining." << endl
             << player1Current->getName() << " has " << player2Current->getStrength() << " strength points remaining." << endl
             << "__________________________________________________________" << endl
             << endl;

        fight(player1Current, player2Current);

        cout << endl
             << "Press enter continue." << endl;
        cin.get();

        currentRound++;

    } while (bothAlive(player1Current, player2Current));
}

void Game::clearTeams()
{
    while (player1Characters.getHead() != nullptr)
    {
        player1Characters.removeHead();
    }

    while (player2Characters.getHead() != nullptr)
    {
        player2Characters.removeHead();
    }
}

void Game::printScore()
{
    int winner;
    string winMessage;

    if (player1Score > player2Score)
    {
        winMessage = "Player 1 wins the tournament!";
    }
    else if (player2Score > player1Score)
    {
        winMessage = "Player 2 wins the tournament!";
    }
    else
    {
        winMessage = "It's a draw!";
    }

    cout << endl
         << "*** Final Score: ***" << endl
         << "Player 1: " << player1Score << endl
         << "Player 2: " << player2Score << endl
         << winMessage << endl;
}

void Game::handleLosersSelection(int selection)
{
    if (selection == 1)
    {
        losers.printCharacters();
    }
    return;
}