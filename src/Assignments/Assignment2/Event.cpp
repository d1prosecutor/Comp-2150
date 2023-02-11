#include <cmath>
#include <iostream>

using namespace std;

#include "Event.h"
#include "ArrivalEvent.h"
#include "PriorityQueue.h"
#include "EventSimulator.h"
#include "Node.h"

// Initialize Class variables
int Event::ID = 0;
int Event::numWorkDays = 0;
PriorityQueue *Event::eventQueue = new PriorityQueue();
PriorityQueue *Event::pendingOrders = new PriorityQueue();

// Constructors
Event::Event() {}
Event::Event(Event *thisEvent, int newTime, int arrivalTime) : currTime(newTime), customerType(thisEvent->customerType),
                                                               orderValue(thisEvent->orderValue), arrivalTime(arrivalTime),
                                                               orderID(thisEvent->orderID)
{
    // Update the number of work days so far
    Event::calcNumWorkDays(newTime);
}

Event::Event(int currTime, string customerType, int orderValue, int arrivalTime) : currTime(currTime), customerType(customerType),
                                                                                   orderValue(orderValue), arrivalTime(arrivalTime),
                                                                                   orderID(++Event::ID)
{

    // Update the number of work days so far
    Event::calcNumWorkDays(currTime);
}

// Class methods
void Event::addToQueue(Event *newEvent)
{
    Event::eventQueue->enqueue(newEvent, newEvent->currTime, newEvent->orderID);
}

void Event::addToPending(Event *newEvent)
{
    Event::pendingOrders->addToLine(newEvent, newEvent->currTime, newEvent->orderID);
}

Event *Event::getNextOrder()
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

void Event::calcNumWorkDays(int currTime)
{
    // Calculate the number of work days
    Event::numWorkDays = ceil(currTime / 8.0f);
}

float Event::calcCostOfBusiness(int numWorkers)
{
    // Calculate the cost of additional workers
    float empWage = 13.50;
    int numStdHrs = 8;
    return (Event::getNumWorkDays() * numStdHrs * empWage * numWorkers) +
           (Event::getNumWorkDays() * numWorkers);
}

float Event::calcFinalProfit(int numWorkers)
{
    return ArrivalEvent::getInitialProfit() - Event::calcCostOfBusiness(numWorkers);
}

int Event::getNumWorkDays()
{
    return Event::numWorkDays;
}

// Instance methods
void Event::processEvent()
{
    // Print out the details common to all the events
    cout << "TIME: " << currTime << " -> Order " << orderID << " (" + customerType + ", $" << orderValue << ") ";
}

int Event::getCurrTime()
{
    return currTime;
}

int Event::getArrivalTime()
{
    return arrivalTime;
}

string Event::getCustomerType()
{
    return customerType;
}

int Event::getOrderValue()
{
    return orderValue;
}

int Event::getOrderID()
{
    return orderID;
}
