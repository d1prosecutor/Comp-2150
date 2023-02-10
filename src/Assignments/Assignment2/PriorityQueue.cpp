#include "PriorityQueue.h"
#include "Node.h"
#include "Event.h"

// Constructors
PriorityQueue::PriorityQueue()
{
    front = nullptr;
}

// Instance methods
void PriorityQueue::enqueue(Event *newEvent, int priority)
{
    Node *temp = front;
    Node *prev = nullptr;

    while (temp != nullptr && temp->getEvent()->getTime() <= priority)
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

Node *PriorityQueue::dequeue()
{
    Node *tempFront = front;

    // dequeue the event from the queue
    front = front->getNext();

    // Free the memory allocated
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

    Event *removedEvent;

    // Get the event to remove from the queue
    if (curr != nullptr)
    {
        // Should never be null
        removedEvent = curr->getEvent();
    }

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
