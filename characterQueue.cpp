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
    if (this->head == nullptr)
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

CharacterNode *CharacterQueue::getHead()
{
    return head;
}

void CharacterQueue::removeHead()
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        // If there is only 1 character in the queue
        if (head == head->nextCharacter)
        {
            head->nextCharacter = nullptr;
            head->prevCharacter = nullptr;
            head = nullptr;
        }
        else
        {
            CharacterNode *oldHead = head;
            // Set the new head to the old head's next value
            CharacterNode *newHead = oldHead->nextCharacter;
            this->head = newHead;
            // Set the new head's previous value to point to the last node in the Queue
            CharacterNode *lastCharacter = oldHead->prevCharacter;
            newHead->prevCharacter = lastCharacter;
            // Set the last node's next value to point to the new head
            lastCharacter->nextCharacter = newHead;

            oldHead->nextCharacter = nullptr;
            oldHead->prevCharacter = nullptr;
        }
    }
}

Character *CharacterQueue::getCharacterType()
{
    return head->character;
}

void CharacterQueue::moveHeadToEnd()
{
}