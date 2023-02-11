#include <iostream>

using namespace std;

#include "PrepareEvent.h"
#include "ShippingEvent.h"
#include "EventSimulator.h"

// Constructors
PrepareEvent::PrepareEvent() {}
PrepareEvent::PrepareEvent(Event *currEvent, int currentTime, int arrivalTime) : Event(currEvent, currentTime, arrivalTime) {}

// Instance methods
void PrepareEvent::processEvent()
{
    // Call the superclass 'processEvent' method to print the details common to all events
    Event::processEvent();

    int processTime = calcProcessTime(getOrderValue());

    // Print the details specific to just events being processed
    cout << "is being prepared "
         << "(prep. time = " << processTime << ")." << endl;

    // Assign a worker to the event being prepared.
    EventSimulator::decrFreeEmp();

    // Calculate the time it will take to process and create a shipping order
    int shippingTime = currTime + processTime;
    Event *newShippingOrder = new ShippingEvent(this, shippingTime, arrivalTime);

    // Add that new shipping order to the list of pending orders
    Event::addToQueue(newShippingOrder);
}

int PrepareEvent::calcProcessTime(int orderValue)
{
    return (orderValue + 200) / 200;
}
