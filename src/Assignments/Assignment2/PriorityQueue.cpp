/***********************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 2
 *
 * REMARKS: Implements the Priority Queue class
 **********************************************/
using namespace std;

#include "PriorityQueue.h"
#include "Node.h"
#include "Event.h"

// Constructors
PriorityQueue::PriorityQueue()
{
    front = nullptr;
}

// Destructor
// Doesn't actually delete anything in this program because every node is deleted
// when removed from the queue in the dequeue method
PriorityQueue::~PriorityQueue()
{
    delete front;
}

// Instance methods
/******************************************************************************
 * enqueue
 *
 * PURPOSE: This Method adds the given event to a queue based on priority
 *          (current time) and the id of the order
 *
 * INPUT PARAMETERS:
 *      newEvent: Event to be added to the queue
 *      priority: The current time in the simulation
 *      id: The id of the event to be added
 *******************************************************************************/
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
/******************************************************************************
 * addToLine
 *
 * PURPOSE: This Method adds the given event to a queue based on customer priority
 *          (primero before standard), time priority and the id of the order
 *
 * INPUT PARAMETERS:
 *      newEvent: Event to be added to the queue
 *      customerType: The customer type (primero vs standard)
 *      priority: The current time in the simulation
 *      id: The id of the event to be added
 *******************************************************************************/
void PriorityQueue::addToLine(Event *newEvent, string customerType, int priority, int id)
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
    if (customerType == "standard")
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

    // Insert the new event into the queue
    if (prev != nullptr)
    {
        prev->setNext(new Node(newEvent, prev->getNext()));
    }
    else
    {
        front = new Node(newEvent, front);
    }
}

/******************************************************************************
 * dequeue
 *
 * PURPOSE: This Method removes and returns the event at the front of the queue
 *******************************************************************************/
Event *PriorityQueue::dequeue()
{
    Node *tempFront = front;

    // dequeue the event from the queue
    front = front->getNext();

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
