#include "Node.h"

// Constructors
Node::Node() {}

Node::Node(Event *newEvent, Node *next) : thisEvent(newEvent), nextEvent(next) {}

// Destructor
Node::~Node()
{
    if (nextEvent == nullptr)
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