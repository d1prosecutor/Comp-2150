#include <iomanip>
#include <iostream>

using namespace std;

#include "ShippingEvent.h"
#include "ArrivalEvent.h"
#include "PrepareEvent.h"
#include "EventSimulator.h"

// Constructors
ShippingEvent::ShippingEvent() {}
ShippingEvent::ShippingEvent(Event *newShipping, int newtime, int arrivalTime) : Event(newShipping, newtime, arrivalTime) {}

// Instance methods
void ShippingEvent::processEvent()
{
    // Call the superclass 'processEvent' method to print the details common to all events
    Event::processEvent();

    // Print the detail specific to just events to be shipped
    cout << "has been shipped. ";

    // truncating the output to 2 decimal places
    cout << fixed << setprecision(2);
    if (customerType == "primero")
    {
        printPrimeroDiscount();
    }
    else if (customerType == "standard")
    {
        printStandardDiscount();
    }
    // End the print line
    cout << endl;

    // The worker who was attending to this shipped order is free to take another order
    EventSimulator::incrFreeEmp();

    if (!Event::lineIsEmpty())
    {
        // Attend to the order at the front of the waiting line
        Event *tempEvent = Event::getNextPending();
        Event *nextEvent = new PrepareEvent(tempEvent, currTime, tempEvent->getArrivalTime());

        // Add this new order to the list of pending orders
        Event::addToQueue(nextEvent);
    }
}

float ShippingEvent::calcDiscount(int orderValue)
{
    return (15 / 100.0f) * (float)orderValue;
}

void ShippingEvent::printPrimeroDiscount()
{
    if (currTime - arrivalTime > 7)
    {
        // Calculate discount here
        float discount = calcDiscount(getOrderValue());

        // Update the profit of the profit to reflect this discount
        ArrivalEvent::updateProfit(-discount);

        // print out the penalty
        cout << "*** Penalty paid: $" << discount << ".";
    }
}

void ShippingEvent::printStandardDiscount()
{
    if (currTime - arrivalTime > 23)
    {
        // Calculate discount here
        float discount = calcDiscount(getOrderValue());

        // Update the profit of the profit to reflect this discount
        ArrivalEvent::updateProfit(-discount);

        // print out the penalty
        cout << "*** Penalty paid: $" << discount << ".";
    }
}