#ifndef GAME_HPP
#define GAME_HPP

#include "character.hpp"
#include "characterQueue.hpp"

class Game
{
private:
    const int TEAM_SIZE = 2;
    CharacterQueue player1Characters;
    CharacterQueue player2Characters;
    CharacterQueue losers;
    int promptPlayerSelection(int);
    std::string setPlayer(CharacterQueue &, int);
    int currentRound;
    void pickTeams(int);
    void runTournament();

public:
    Game();
    void playGame();
    bool allAlive();
    void fight();
    void driver();
    void deallocateMem();
};

#endif