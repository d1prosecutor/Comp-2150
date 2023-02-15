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

    //Destructor
    ~Node();

    // Instance methods
    Node *getNext();
    Event *getEvent();
    void setNext(Node *);
};