/***************************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 2
 *
 * REMARKS: Interface for the Priority Queue Class
 **************************************************/
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
    Event *dequeue();
    bool isEmpty() const;
    void enqueue(Event *, int, int);
    void addToLine(Event *, string, int, int);
};