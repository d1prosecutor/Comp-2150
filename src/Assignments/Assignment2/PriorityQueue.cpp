#include "PriorityQueue.h"
#include "Node.h"
#include "Event.h"

// Constructors
PriorityQueue::PriorityQueue()
{
    front = nullptr;
}

// Instance methods
void PriorityQueue::enqueue(Event *newEvent, int priority, int id)
{
    Node *temp = front;
    Node *prev = nullptr;

    // Order the events by TIME-priority
    while (temp != nullptr && temp->getEvent()->getCurrTime() < priority)
    {
        prev = temp;
        temp = temp->getNext();
    }

    // If the times are the same, order the events by ORDER_ID-priority
    if (temp != nullptr && temp->getEvent()->getCurrTime() == priority)
    {
        while (temp != nullptr && temp->getEvent()->getOrderID() < id)
        {
            prev = temp;
            temp = temp->getNext();
        }
    }

    if (prev != nullptr)
    {
        prev->setNext(new Node(newEvent, prev->getNext()));
    }
    else
    {
        front = new Node(newEvent, front);
    }
}

// This organizes the waiting line to attend to PRIMERO customers first
void PriorityQueue::addToLine(Event *newEvent, int priority, int id)
{
    Node *temp = front;
    Node *prev = nullptr;

    // First order the events by all PRIMERO customers before STANDARD customers
    while (temp != nullptr && temp->getEvent()->getCustomerType() != "standard")
    {
        prev = temp;
        temp = temp->getNext();
    }

    // If the order to be added to the waiting line is a STANDARD, then it should be at
    // its correct spot in the STANDARD section of the line, else if it is PRIMERO, then
    // it should go at the end of the PRIMERO section of the line(just before the first STANDARD customer)
    // -> Since the input file is time ordered, there will be no line cutting/jumping
    if (newEvent->getCustomerType() == "standard")
    {
        // Then Order the events by TIME priority
        while (temp != nullptr && temp->getEvent()->getCurrTime() < priority)
        {
            prev = temp;
            temp = temp->getNext();
        }

        // If the times are the same, order the events by ORDER_ID priority
        if (temp != nullptr && temp->getEvent()->getCurrTime() == priority)
        {
            while (temp != nullptr && temp->getEvent()->getOrderID() < id)
            {
                prev = temp;
                temp = temp->getNext();
            }
        }
    }

    // Insert the new event into the list
    if (prev != nullptr)
    {
        prev->setNext(new Node(newEvent, prev->getNext()));
    }
    else
    {
        front = new Node(newEvent, front);
    }
}

Node *PriorityQueue::dequeue()
{
    Node *tempFront = front;

    // dequeue the event from the queue
    front = front->getNext();

    // Free the memory allocated here
    //
    return tempFront;

    //
    // Check for memory leaks here
    //
}

bool PriorityQueue::isEmpty()
{
    return front == nullptr;
}

Node *PriorityQueue::peek()
{
    return front;
}
