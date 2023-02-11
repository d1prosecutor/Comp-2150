#include <iostream>
#include <cmath>

using namespace std;

#include "Event.h"
#include "ArrivalEvent.h"
#include "PriorityQueue.h"
#include "EventSimulator.h"
#include "Node.h"

// Initialize Class variables
int Event::ID = 0;
int Event::numWorkers = 0;
int Event::numWorkDays = 0;
int Event::numFreeWorkers = 1;
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
    Event::pendingOrders->enqueue(newEvent, newEvent->currTime, newEvent->orderID);
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

float Event::calcCostOfBusiness()
{
    // Calculate the cost of additional workers
    float empWage = 13.50;
    int numStdHrs = 8;
    return (Event::getNumWorkDays() * numStdHrs * empWage * Event::numWorkers) +
           (Event::getNumWorkDays() * Event::numWorkers);
}

float Event::calcFinalProfit()
{
    return ArrivalEvent::getInitialProfit() - Event::calcCostOfBusiness();
}

void Event::calcNumWorkDays(int currTime)
{
    // Calculate the number of work days
    Event::numWorkDays = ceil(currTime / 8.0f);
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

int Event::getNumFreeWorkers()
{
    return Event::numFreeWorkers;
}

int Event::getNumWorkDays()
{
    return Event::numWorkDays;
}
