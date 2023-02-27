/***********************************************************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 2
 *
 * REMARKS: Implements the Node class. Each Node object is a container for an Event
 ***********************************************************************************/
#include "Node.h"

// Constructors
Node::Node() {}

Node::Node(Event *newEvent, Node *next) : thisEvent(newEvent), nextEvent(next) {}

// Destructor; already here by default
Node::~Node()
{
    if (nextEvent != nullptr)
    {
        delete nextEvent;
    }
}

// Accesssors
Node *Node::getNext() const
{
    return nextEvent;
}

Event *Node::getEvent() const
{
    return thisEvent;
}

// Mutators
void Node::setNext(Node *newEvent)
{
    nextEvent = newEvent;
}