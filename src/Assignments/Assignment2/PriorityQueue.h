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

    // Instance methods
    Node *peek();
    bool isEmpty();
    Node *dequeue();
    void enqueue(Event *, int, int);
    void addToLine(Event *, int, int);
};