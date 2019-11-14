/**************************************************************************************
** Program name: menu.hpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Declaration and header file for the Menu class.
**************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>

bool startMenu(std::string);

int gameMenuRange(std::string, int, int);

int multiOptionMenu(std::vector<std::string>);

#endif
