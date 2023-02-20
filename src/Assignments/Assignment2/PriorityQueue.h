#pragma once

class Event;
class Node;

class PriorityQueue
{
private:
    Node *front;

public:
    // Constructors
    PriorityQueue();

    // Destructor
    ~PriorityQueue();

    // Instance methods
    bool isEmpty() const;
    Event *dequeue();
    void enqueue(Event *, int, int);
    void addToLine(Event *, int, int);
};