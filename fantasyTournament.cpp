/**************************************************************************************
** Program name: fantasyCombat.cpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Implemetation of the main() function for the Fantasy Combat game.
**************************************************************************************/
#include <vector>
#include <string>
#include <iostream>
#include "game.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    Game newGame;

    newGame.playGame();

    return 0;
}