/****************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 2
 *
 * REMARKS: Interface for the Node Class
 ****************************************/
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