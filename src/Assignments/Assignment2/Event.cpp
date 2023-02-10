#include "Event.h"
#include "PriorityQueue.h"
#include "ShippingEvent.h"
#include "Node.h"

#include <iostream>

using namespace std;

// Initializing the static variables
int Event::ID = 0;
int Event::numFreeWorkers = 0;
PriorityQueue *Event::eventQueue = new PriorityQueue();
PriorityQueue *Event::pendingOrders = new PriorityQueue();

// Constructors
Event::Event() {}
Event::Event(Event *thisEvent, int newTime) : time(newTime),
                                              customerType(thisEvent->customerType), orderValue(thisEvent->orderValue), orderID(Event::ID++)
{
}

Event::Event(int time, string customerType, int orderValue) : time(time), customerType(customerType),
                                                              orderValue(orderValue), orderID(Event::ID++) {}

// Class methods
void *Event::addToQueue(Event *newEvent)
{
    Event::eventQueue->enqueue(newEvent, newEvent->getTime());
}

void *Event::addToPending(Event *newEvent)
{
    Event::pendingOrders->enqueue(newEvent, newEvent->getTime());
}

Event *Event::getNextEvent()
{
    return Event::eventQueue->dequeue()->getEvent();
}

Event *Event::getNextPending()
{
    return Event::pendingOrders->dequeue()->getEvent();
}

bool Event::queueIsEmpty()
{
    return Event::eventQueue->isEmpty();
}

bool Event::lineIsEmpty()
{
    return Event::pendingOrders->isEmpty();
}

// Instance methods
void Event::processEvent()
{
    // Print out the details common to all the events
    cout << "TIME: " << time << " -> Order " + orderID << "(" + customerType + ", $" << orderValue + ")";
}

int Event::getTime()
{
    return time;
}

string Event::getCustomerType()
{
    return customerType;
}

int Event::getOrderValue()
{
    return orderValue;
}

int Event::getNumFreeWorkers()
{
    return Event::numFreeWorkers;
}

void Event::setTime(int newTime)
{
    time = newTime;
}
