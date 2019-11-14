#ifndef GAME_HPP
#define GAME_HPP

#include "character.hpp"
#include "characterQueue.hpp"

class Game
{
private:
    const int TEAM_SIZE = 5;
    CharacterQueue player1Characters;
    CharacterQueue player2Characters;
    CharacterQueue losers;
    void pickTeams(int);
    int promptPlayerSelection(int);
    std::string setPlayer(CharacterQueue &, int);
    int currentRound;

public:
    Game();
    void playGame();
    bool allAlive();
    void fight();
    void driver();
    void deallocateMem();
};

#endif