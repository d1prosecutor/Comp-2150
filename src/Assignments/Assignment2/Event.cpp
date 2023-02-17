#include <iostream>

using namespace std;

#include "Event.h"
#include "Order.h"

// Constructors
Event::Event() {}

Event::Event(Order *newOrder) : thisOrder(newOrder) {}

Event::Event(Event *thisEvent, int newTime)
{
    // Initialize the order instance variable with the same order contained in the event passed in
    thisOrder = thisEvent->thisOrder;
    // thisOrder = new Order(newTime, thisEvent->getCustomerType(), thisEvent->getOrderValue(), thisEvent->getArrTime());
    // thisOrder = new Order(*thisEvent->getOrder());

    // Update the current Time of the current event
    thisOrder->setCurrTime(newTime);
}

// Empty Pure Virtual Destructor implementation which is necessary for the code to compile
Event::~Event() {}

// Instance methods
void Event::processEvent(EventSimulator *thisSimulation)
{
    // Print out the details common to all the events
    cout << "TIME: " << thisOrder->getCurrTime() << " -> Order " << thisOrder->getOrderID()
         << " (" + thisOrder->getCustomerType() + ", $" << thisOrder->getOrderValue() << ") ";
}

// Accessors

Order *Event::getOrder() const
{
    return thisOrder;
}

int Event::getCurrTime() const
{
    return thisOrder->getCurrTime();
}

int Event::getOrderID() const
{
    return thisOrder->getOrderID();
}

int Event::getOrderValue() const
{
    return thisOrder->getOrderValue();
}

int Event::getArrTime() const
{
    return thisOrder->getArrivalTime();
}

string Event::getCustomerType() const
{
    return thisOrder->getCustomerType();
}
