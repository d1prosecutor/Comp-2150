#include <iostream>

using namespace std;

#include "PrepareEvent.h"
#include "ShippingEvent.h"

// Constructors
PrepareEvent::PrepareEvent() {}
PrepareEvent::PrepareEvent(Event *currEvent, int currentTime, int arrivalTime) : Event(currEvent, currentTime, arrivalTime) {}

// Instance methods
void PrepareEvent::processEvent()
{
    // Call the superclass 'processEvent' method to print the details common to all events
    Event::processEvent();

    processTime = calcProcessTime(getOrderValue());

    // Print the details specific to just events being processed
    cout << "is being prepared "
         << "(prep. time = " << processTime << ")." << endl;

    // Assign a worker to the event being prepared.
    Event::numFreeWorkers--;

    int shippingTime = currTime + processTime;

    Event *newShippingOrder = new ShippingEvent(this, shippingTime, arrivalTime);

    Event::addToQueue(newShippingOrder);
}

int PrepareEvent::calcProcessTime(int orderValue)
{
    return (orderValue + 200) / 200;
}
