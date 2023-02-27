/***********************************************************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 2
 *
 * REMARKS: Implements the Event class which is an abstract class that has three
 *          subclasses
 ***********************************************************************************/
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

    // Update the current Time of the current event
    thisOrder->setCurrTime(newTime);
}

// Empty Pure Virtual Destructor implementation which is necessary for the code to compile
Event::~Event() {}

// Instance methods
/******************************************************************************
 * processEvent
 *
 * PURPOSE: This method prints out details common to all types of events and
 *          activates polymorphism for the subclass implementations of the method
 *
 * INPUT PARAMETERS:
 *      thisSimulation: The current Simulation in progress
 *******************************************************************************/
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
