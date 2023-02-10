#include "ShippingEvent.h"
#include "PrepareEvent.h"
#include "Node.h"
#include <iostream>

using namespace std;

// Constructors
ShippingEvent::ShippingEvent() {}
ShippingEvent::ShippingEvent(Event *newShipping, int newtime) : Event(newShipping, newtime), arrivalTime(newShipping->getTime()) {}

// Instance methods
void ShippingEvent::processEvent()
{
    // Call the superclass 'processEvent' method to print the details common to all events
    this->Event::processEvent();

    // Print the detail specific to just events to be shipped
    cout << "has been shipped." << endl;

    if (getCustomerType() == "primero")
    {
        if (getTime() - arrivalTime > 7)
        {
            // Calculate discount here

            // Insert penalty
        }
    }
    else if (getCustomerType() == "standard")
    {
        if (getTime() - arrivalTime > 23)
        {
            // Calculate discount here

            // Insert penalty here
        }
    }

    // The worker who was attending to this shipped order is free to take another order
    numFreeWorkers++;

    if (!Event::lineIsEmpty())
    {
        // Attend to the order at the front of the waiting line
        Event *nextEvent = new PrepareEvent(Event::getNextPending());

        // Add this new order to the list of pending orders
        Event::addToQueue(nextEvent);
    }
}

float ShippingEvent::calcDiscount(int orderValue)
{
    return (15 / 100.0) * (float)orderValue;
}