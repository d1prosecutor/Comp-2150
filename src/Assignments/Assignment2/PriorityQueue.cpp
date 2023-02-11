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

    // Order the events by TIME priority
    while (temp != nullptr && temp->getEvent()->getCurrTime() < priority)
    {
        prev = temp;
        temp = temp->getNext();
    }

    // If the times are the same, order the events by ORDERID priority
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

Node *PriorityQueue::peek()
{
    return front;
}

Event *PriorityQueue::remove(Event *thisEvent)
{
    Node *curr = front;
    Node *prev = nullptr;

    while (curr != nullptr && curr->getEvent() != thisEvent)
    {
        prev = curr;
        curr = curr->getNext();
    }

    Event *removedEvent = nullptr;

    // Get the event to remove from the queue
    removedEvent = curr->getEvent();

    if (prev == nullptr)
    {
        front->setNext(front->getNext());
    }
    else
    {
        prev->setNext(curr->getNext());
    }

    return removedEvent;
}

bool PriorityQueue::isEmpty()
{
    return front == nullptr;
}
