/**************************************************************************************
** Program name: inputValidation.hpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Declaration and header file for the isIntegerInput and convertInputToIt
** functions.
**************************************************************************************/
#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP

#include <string>

bool isIntegerInput(std::string);

int convertInputToInt();

bool isAlphaNumInput(const std::string &);

#endif