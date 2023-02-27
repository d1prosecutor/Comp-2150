/***********************************************************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 2
 *
 * REMARKS: Implements the Shipping-Event class which is a subclass of the Event class
 ***********************************************************************************/
#include <iomanip>
#include <iostream>

using namespace std;

#include "Order.h"
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
ShippingEvent::~ShippingEvent()
{
    delete (getOrder());
}

// Instance methods
/******************************************************************************
 * processEvent
 *
 * PURPOSE: This Method Ships an order to the customer, accounting for late
 *          shipping where necessary
 *
 * INPUT PARAMETERS:
 *      thisSimulation: The current Simulation in progress
 *******************************************************************************/
void ShippingEvent::processEvent(EventSimulator *thisSimulation)
{
    // Call the superclass 'processEvent' method to print the details common to all events
    Event::processEvent(thisSimulation);

    // Print the detail specific to just events to be shipped
    cout << "has been shipped. ";

    // Check if there's need for a discount (in cases of late shipping)
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

    // Check if theres any order pending processing
    if (!thisSimulation->pendingIsEmpty())
    {
        // Attend to the order at the front of the waiting line
        Event *tempEvent = thisSimulation->getNextPending();
        Event *nextEvent = new PrepareEvent(tempEvent, getCurrTime());

        // Add this new order to the list of pending orders
        thisSimulation->addToQueue(nextEvent, nextEvent->getCurrTime(), nextEvent->getOrderID());
    }
}

/************************************************************************
 * calcDiscount
 *
 * PURPOSE: This Method calculates the discount to be applied to an order
 *
 * INPUT PARAMETERS:
 *      orderValue: The original value of the order
 ************************************************************************/
float ShippingEvent::calcDiscount(int orderValue) const
{
    return (ShippingEvent::discount) * (float)orderValue;
}

/******************************************************************************
 * printPrimeroDiscount
 *
 * PURPOSE: This Method updates the owner's profit based on the discount on a
 *          primero order and prints the stats
 *
 * INPUT PARAMETERS:
 *      thisSimulation: The current Simulation in progress
 *******************************************************************************/
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

/******************************************************************************
 * printStandardDiscount
 *
 * PURPOSE: This Method updates the owner's profit based on the discount on a
 *          standard order and prints the stats
 *
 * INPUT PARAMETERS:
 *      thisSimulation: The current Simulation in progress
 *******************************************************************************/
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