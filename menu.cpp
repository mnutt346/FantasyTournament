/**************************************************************************************
** Program name: menu.cpp
** Author: Michael Nutt
** Date: 10/31/2019
** Description: Definition of the menu functions. The menu functions determine whether
** to start a new game or exit the program, and define all necessary parameters for the
** game to run by prompting the user for their desired settings.
**************************************************************************************/

#include "menu.hpp"
#include "inputValidation.hpp"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/* Summary: Prompts the user to either start the program or quit
 * Param: string program -> represents the title of the program; used to inform the user
 * as to which program they are starting
 * Return: boolean value representing the user's decision (true = start the program, false = quit)
 */
bool startMenu(string program)
{
    int selection;

    cout << endl
         << "Select one of the following options by entering the number representing your selection." << endl;
    cout << "1: Start program: " << program << "." << endl;
    cout << "2: Quit." << endl;

    // Validate input
    selection = convertInputToInt();

    // While the user enter's input other than 1 or 2:
    while (selection != 1 && selection != 2)
    {
        cout << "Invalid input. Please enter either 1 or 2." << endl;
        selection = convertInputToInt();
    }

    if (selection == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Summary: Prompts the user to to enter a range of values to be used as game settings.
 * Param: string setting -> tells the user which setting they are selecting
 * Param: int minVal -> minimum allowable value
 * Param: int maxVal -> maximum allowable alue
 * Return: integer value representing the users choice
 */
int gameMenuRange(string setting, int minVal, int maxVal)
{
    int input;

    cout << endl
         << "Please select " << setting << " between " << minVal << " and " << maxVal << "." << endl;

    // Validate input
    input = convertInputToInt();

    // While the input is out of range
    while (input < minVal || input > maxVal)
    {
        cout << "Invalid input." << endl
             << "Please enter an integer between " << minVal << " and " << maxVal << "." << endl;

        // Re-validate input
        input = convertInputToInt();
    }

    return input;
}

/* Summary: Prompts the user to to select between various options.
 * Param: a vector of strings that represent each possible option.
 * Return: integer value representing the users choice
 */
int multiOptionMenu(vector<string> options)
{
    int input;
    int counter = 1;

    cout << endl
         << "Select one of the following:" << endl;
    // Print options
    for (string option : options)
    {
        cout << counter << ". " << option << endl;
        counter++;
    }

    input = convertInputToInt();

    // While user input is invalid
    while (input < 1 || input > options.size())
    {
        counter = 1;

        cout << "Invalid input." << endl
             << "Please select one of the following:" << endl;
        // Print options
        for (string option : options)
        {
            cout << counter << ". " << option << endl;
            counter++;
        }

        // revalidate input
        input = convertInputToInt();
    }

    return input;
}