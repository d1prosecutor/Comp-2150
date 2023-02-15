#include <cmath>
#include <iostream>

using namespace std;

#include "Event.h"
#include "Order.h"

// Initialize Class variables
int Event::numWorkDays = 0;

// Constructors
Event::Event() {}

Event::Event(Order *newOrder) : thisOrder(newOrder)
{
    // Update the number of work days so far
    Event::calcNumWorkDays(newOrder->getCurrTime());
}

Event::Event(Event *thisEvent, int newTime)
{
    // Initialize the order instance variable with the same order contained in the event passed in
    thisOrder = thisEvent->thisOrder;

    // Update the current Time of the current event
    thisEvent->thisOrder->setCurrTime(newTime);

    // Update the number of work days so far
    Event::calcNumWorkDays(newTime);
}

// Destructor
Event::~Event() {}

// Class methods
void Event::calcNumWorkDays(int currTime)
{
    // Calculate the number of work days
    Event::numWorkDays = ceil(currTime / 8.0f);
}

int Event::getNumWorkDays()
{
    return Event::numWorkDays;
}

// Instance methods
void Event::processEvent(EventSimulator *thisSimulation)
{
    // Print out the details common to all the events
    cout << "TIME: " << thisOrder->getCurrTime() << " -> Order " << thisOrder->getOrderID()
         << " (" + thisOrder->getCustomerType() + ", $" << thisOrder->getOrderValue() << ") ";
}

const int Event::getCurrTime()
{
    return thisOrder->getCurrTime();
}

const int Event::getOrderID()
{
    return thisOrder->getOrderID();
}

const int Event::getOrderValue()
{
    return thisOrder->getOrderValue();
}

const int Event::getArrTime()
{
    return thisOrder->getArrivalTime();
}

const string Event::getCustomerType()
{
    return thisOrder->getCustomerType();
}
