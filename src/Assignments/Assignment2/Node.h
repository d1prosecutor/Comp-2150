#pragma once
class Event;

class Node
{
private:
    Event *thisEvent;
    Node *nextEvent;

public:
    // Constructors
    Node();
    Node(Event *, Node *);

    // Instance methods
    Event *getEvent();
    Node *getNext();
    void setNext(Node *);
};