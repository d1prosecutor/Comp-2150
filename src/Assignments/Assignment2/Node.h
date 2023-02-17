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

    // Destructor
    ~Node();

    // Accessors
    Node *getNext() const;
    Event *getEvent() const;

    // Mutators
    void setNext(Node *);
};