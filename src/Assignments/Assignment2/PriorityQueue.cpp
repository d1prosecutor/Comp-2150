#include "PriorityQueue.h"
#include "Node.h"
#include "Event.h"

// Constructors
PriorityQueue::PriorityQueue()
{
    front = nullptr;
}

// Destructor; already here by default
// PriorityQueue::~PriorityQueue()
// {
//     delete front;
// }

// Instance methods
void PriorityQueue::enqueue(Event *newEvent, int priority, int id)
{
    Node *temp = front;
    Node *prev = nullptr;

    // Order the events by TIME-priority
    // If the times are the same, order the events by ORDER_ID-priority
    while (temp != nullptr && ((temp->getEvent()->getCurrTime() < priority) ||
                               (temp->getEvent()->getCurrTime() == priority && temp->getEvent()->getOrderID() < id)))
    {
        prev = temp;
        temp = temp->getNext();
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
        // If the times are the same, order the events by ORDER_ID priority
        while (temp != nullptr && ((temp->getEvent()->getCurrTime() < priority) ||
                                   (temp->getEvent()->getCurrTime() == priority && temp->getEvent()->getOrderID() < id)))
        {
            prev = temp;
            temp = temp->getNext();
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

Event *PriorityQueue::dequeue()
{
    Node *tempFront = front;

    // dequeue the event from the queue
    front = front->getNext();

    // Free the memory allocated here
    //
    Event *tempEvent = tempFront->getEvent();

    // Free the memory taken by the removed node
    // First unlink it from the node it points to
    tempFront->setNext(nullptr);
    delete tempFront;

    return tempEvent;
}

bool PriorityQueue::isEmpty() const
{
    return front == nullptr;
}
