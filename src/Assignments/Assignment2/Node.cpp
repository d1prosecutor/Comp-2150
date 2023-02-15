#include "Node.h"

// Constructors
Node::Node() {}

Node::Node(Event *newEvent, Node *next) : thisEvent(newEvent), nextEvent(next) {}

// Destructor
Node::~Node() {}

// Instance methods
Node *Node::getNext()
{
    return nextEvent;
}

Event *Node::getEvent()
{
    return thisEvent;
}

void Node::setNext(Node *newEvent)
{
    nextEvent = newEvent;
}