#include "Node.h"

class Event;

// Constructors
Node::Node() {}

Node::Node(Event *newEvent, Node *next) : thisEvent(newEvent), nextEvent(next) {}

// Instance methods
Event *Node::getEvent()
{
    return thisEvent;
}

Node *Node::getNext()
{
    return nextEvent;
}

void Node::setNext(Node *newEvent)
{
    nextEvent = newEvent;
}