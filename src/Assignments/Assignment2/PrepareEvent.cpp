#include <iostream>

using namespace std;

#include "PrepareEvent.h"
#include "ShippingEvent.h"
#include "EventSimulator.h"

// Initializing class variables
int PrepareEvent::pricePerHour = 200;

// Constructors
PrepareEvent::PrepareEvent() {}
PrepareEvent::PrepareEvent(Event *currEvent, int currentTime) : Event(currEvent, currentTime) {}

// Destructor; already here by default
// PrepareEvent::~PrepareEvent() {}

// Instance methods
void PrepareEvent::processEvent(EventSimulator *thisSimulation)
{
    // Call the superclass 'processEvent' method to print the details common to all events
    Event::processEvent(thisSimulation);

    int processTime = calcProcessTime(getOrderValue());

    // Print the details specific to just events being processed
    cout << "is being prepared "
         << "(prep. time = " << processTime << ")." << endl;

    // Assign a worker to the event being prepared.
    thisSimulation->decrFreeEmp();

    // Calculate the time it will take to process and create a shipping order
    int shippingTime = getCurrTime() + processTime;
    Event *newShippingOrder = new ShippingEvent(this, shippingTime);

    // Add that new shipping order to the list of pending orders
    thisSimulation->addToQueue(newShippingOrder, newShippingOrder->getCurrTime(), newShippingOrder->getOrderID());
}

int PrepareEvent::calcProcessTime(int orderValue) const
{
    return (orderValue + PrepareEvent::pricePerHour) / PrepareEvent::pricePerHour;
}
