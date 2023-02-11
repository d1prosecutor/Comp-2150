#pragma once

class Event;
class Node;

class PriorityQueue
{
private:
    Node *front;
    // Node *back;

public:
    // Constructors
    PriorityQueue();

    // Instance methods
    void enqueue(Event *, int, int);
    Node *dequeue();
    Node *peek();
    Event *remove(Event *);
    bool isEmpty();
};