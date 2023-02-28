/***********************************************************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 2
 *
 * REMARKS: Implements the Arrival-Event class which is a subclass of the Event class
 ***********************************************************************************/
#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)
#include <iostream>

using namespace std;

#include "ArrivalEvent.h"
#include "PrepareEvent.h"
#include "EventSimulator.h"

// Constructors
ArrivalEvent::ArrivalEvent() {}

ArrivalEvent::ArrivalEvent(Order *newOrder) : Event(newOrder) {}

// Destructor
ArrivalEvent::~ArrivalEvent() {}

// Instance methods
/******************************************************************************
 * processEvent
 *
 * PURPOSE: This Method acknowledges the arrival of a new order and starts the
 *          processing of the order
 *
 * INPUT PARAMETERS:
 *      thisSimulation: The current Simulation in progress
 *******************************************************************************/
void ArrivalEvent::processEvent(EventSimulator *thisSimulation)
{
    // Just checking to make sure invalid orders dont get processed
    if (getOrderValue() > 0)
    {
        // Add new customer from the file into the waiting line here
        thisSimulation->addToPending(this, getCustomerType(), getCurrTime(), getOrderID());

        // Call the superclass 'processEvent' method to print the details common to all events
        Event::processEvent(thisSimulation);

        // Print the detail specific to just arrival events
        cout << "arrives. " << endl;

        // Start processing the next event in the queue if there is an available worker
        if (thisSimulation->getFreeEmp() > 0)
        {
            Event *tempPending = thisSimulation->getNextPending();

            // Get the next order in the pending orders list and start processing it
            Event *processOrder = new PrepareEvent(tempPending, getCurrTime());

            // Insert the order in the pending events queue
            thisSimulation->addToQueue(processOrder, processOrder->getCurrTime(), processOrder->getOrderID());

            // When done with the arrival event, free its memory
            delete this;
        }

        // Read the next order from the file and add it to the event queue
        thisSimulation->readNextLine();
    }
}
