#include <iostream>

using namespace std;

#include "ShippingEvent.h"
#include "ArrivalEvent.h"
#include "PrepareEvent.h"

// Constructors
ShippingEvent::ShippingEvent() {}
ShippingEvent::ShippingEvent(Event *newShipping, int newtime, int arrivalTime) : Event(newShipping, newtime, arrivalTime) {}

// Instance methods
void ShippingEvent::processEvent()
{
    // Call the superclass 'processEvent' method to print the details common to all events
    Event::processEvent();

    // Print the detail specific to just events to be shipped
    cout << "has been shipped. "
         << "arrival time is: " << arrivalTime;

    float discount = 0;
    if (customerType == "primero")
    {
        if (currTime - arrivalTime > 7)
        {
            // Calculate discount here
            discount = calcDiscount(getOrderValue());

            // Update the profit of the profit to reflect this discount
            ArrivalEvent::updateProfit(-discount);

            // print out the penalty
            cout << "*** Penalty paid: $" << discount << ".";
        }
    }
    else if (customerType == "standard")
    {
        if (currTime - arrivalTime > 23)
        {
            // Calculate discount here
            discount = calcDiscount(getOrderValue());

            // Update the profit of the profit to reflect this discount
            ArrivalEvent::updateProfit(-discount);

            // print out the penalty
            cout << "*** Penalty paid: $" << discount << ".";
        }
    }
    // End the print line
    cout << endl;

    // The worker who was attending to this shipped order is free to take another order
    numFreeWorkers++;

    if (!Event::lineIsEmpty())
    {
        // Attend to the order at the front of the waiting line
        Event *nextEvent = new PrepareEvent(Event::getNextPending(), currTime, arrivalTime);

        // Add this new order to the list of pending orders
        Event::addToQueue(nextEvent);
    }
}

float ShippingEvent::calcDiscount(int orderValue)
{
    return (15 / 100.0f) * (float)orderValue;
}