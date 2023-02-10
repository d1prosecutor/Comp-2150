#include "PrepareEvent.h"
#include "ShippingEvent.h"
#include "PriorityQueue.h"
#include "Node.h"
#include <iostream>

using namespace std;

// Constructors
PrepareEvent::PrepareEvent() {}
PrepareEvent::PrepareEvent(Event *currEvent) : Event(currEvent, currEvent->getTime()) {}

// Instance methods
void PrepareEvent::processEvent()
{
    // Call the superclass 'processEvent' method to print the details common to all events
    this->Event::processEvent();

    // Print the details specific to just events being processed
    cout << "is being prepared"
         << "(prep. time = " << processTime << ").";

    // Assign a worker to the event being prepared.
    Event::numFreeWorkers--;

    processTime = calcProcessTime(getOrderValue());

    int shippingTime = time + processTime;

    Event *newShippingOrder = new ShippingEvent(this, shippingTime);

    Event::addToQueue(newShippingOrder);
}

int PrepareEvent::calcProcessTime(int orderValue)
{
    return (orderValue + 200) / 200;
}
