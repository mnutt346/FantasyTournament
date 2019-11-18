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
    void pickTeams(int);
    void runTournament();
    void fight(Character *, Character *);
    bool allAlive();
    bool bothAlive(Character *&, Character *&);

public:
    Game();
    void playGame();
    void deallocateMem();
};

#endif