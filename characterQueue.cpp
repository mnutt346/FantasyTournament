/**************************************************************************************
** Program name: character.cpp
** Author: Michael Nutt
** Date: 11/13/2019
** Description: Implementation file for the CharacterQueue class.
**************************************************************************************/
#include "characterQueue.hpp"

CharacterQueue::CharacterQueue()
{
    head = nullptr;
}

CharacterQueue::~CharacterQueue()
{
    deallocateMem();
}

void CharacterQueue::deallocateMem()
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        CharacterNode *current = head;

        do
        {
            CharacterNode *temp = current->nextCharacter;

            current->prevCharacter = nullptr;
            current->nextCharacter = nullptr;
            delete current;

            current = temp;

        } while (current != head);

        head->nextCharacter = nullptr;
        head->nextCharacter = nullptr;
        head = nullptr;
    }
}

bool CharacterQueue::isEmpty()
{
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CharacterQueue::addToEnd(Character *newCharacter)
{
    CharacterNode *newNode = new CharacterNode(newCharacter);

    // If the queue is currently empty
    if (isEmpty())
    {
        head = newNode;
        head->nextCharacter = newNode;
        head->prevCharacter = newNode;
    }
    else
    {
        // Set the new character node's next value to the current head
        newNode->nextCharacter = head;
        // Set the new character node's prev value to the previous back of the list (pointed to by the head's prev value)
        CharacterNode *oldEnd = head->prevCharacter;
        newNode->prevCharacter = oldEnd;
        // Set the previous end node's next value to the new character node
        oldEnd->nextCharacter = newNode;
        // Set the head's prev value to the new character node
        head->prevCharacter = newNode;
    }
}