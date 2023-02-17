#include <iomanip>
#include <iostream>

using namespace std;

#include "ShippingEvent.h"
#include "PrepareEvent.h"
#include "EventSimulator.h"

// Initializing Class Variables
float ShippingEvent::discount = 15 / 100.0f;
int ShippingEvent::primeroLateShip = 8;
int ShippingEvent::standardLateShip = 24;
// Constructors
ShippingEvent::ShippingEvent() {}
ShippingEvent::ShippingEvent(Event *newShipping, int newtime) : Event(newShipping, newtime) {}

// Destructor
ShippingEvent::~ShippingEvent() {}

// Instance methods
void ShippingEvent::processEvent(EventSimulator *thisSimulation)
{
    // Call the superclass 'processEvent' method to print the details common to all events
    Event::processEvent(thisSimulation);

    // Print the detail specific to just events to be shipped
    cout << "has been shipped. ";

    // truncating the output to 2 decimal places
    cout << fixed << setprecision(2);
    if (getCustomerType() == "primero")
    {
        printPrimeroDiscount(thisSimulation);
    }
    else if (getCustomerType() == "standard")
    {
        printStandardDiscount(thisSimulation);
    }
    // End the print line
    cout << endl;

    // The worker who was attending to this shipped order is free to take another order
    thisSimulation->incrFreeEmp();

    if (!thisSimulation->lineIsEmpty())
    {
        // Attend to the order at the front of the waiting line
        Event *tempEvent = thisSimulation->getNextPending();
        Event *nextEvent = new PrepareEvent(tempEvent, getCurrTime());

        // Add this new order to the list of pending orders
        thisSimulation->addToQueue(nextEvent, nextEvent->getCurrTime(), nextEvent->getOrderID());
    }
}

float ShippingEvent::calcDiscount(int orderValue) const
{
    return (ShippingEvent::discount) * (float)orderValue;
}

void ShippingEvent::printPrimeroDiscount(EventSimulator *thisSimulation) const
{
    if (getCurrTime() - getArrTime() >= ShippingEvent::primeroLateShip)
    {
        // Calculate discount here
        float discount = calcDiscount(getOrderValue());

        // Update the profit of the profit to reflect this discount
        thisSimulation->updateProfit(-discount);

        // print out the penalty
        cout << "*** Penalty paid: $" << discount << ".";
    }
}

void ShippingEvent::printStandardDiscount(EventSimulator *thisSimulation) const
{
    if (getCurrTime() - getArrTime() >= ShippingEvent::standardLateShip)
    {
        // Calculate discount here
        float discount = calcDiscount(getOrderValue());

        // Update the profit of the profit to reflect this discount
        thisSimulation->updateProfit(-discount);

        // print out the penalty
        cout << "*** Penalty paid: $" << discount << ".";
    }
}