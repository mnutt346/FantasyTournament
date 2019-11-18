/**************************************************************************************
** Program name: characterQueue.hpp
** Author: Michael Nutt
** Date: 11/13/2019
** Description: Declaration and header file for the CharacterQueue class.
**************************************************************************************/
#ifndef CHARACTERQUEUE_HPP
#define CHARACTERQUEUE_HPP

#include "character.hpp"

struct CharacterNode
{

    Character *character;
    CharacterNode *nextCharacter;
    CharacterNode *prevCharacter;

    CharacterNode(Character *&current, CharacterNode *next = nullptr, CharacterNode *prev = nullptr)
    {
        character = current;
        nextCharacter = next;
        prevCharacter = prev;
    }
};

class CharacterQueue
{
private:
    CharacterNode *head;
    int size;

public:
    CharacterQueue();
    ~CharacterQueue();
    void deallocateMem();
    bool isEmpty();
    void addToEnd(Character *);
    void moveHeadToEnd();
    CharacterNode *getHead();
    void removeHead();
    Character *getCharacterType();
    void printCharacters();
};

#endif