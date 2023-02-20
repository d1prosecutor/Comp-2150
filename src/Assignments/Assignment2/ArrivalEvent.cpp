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

// Instance methods
void ArrivalEvent::processEvent(EventSimulator *thisSimulation)
{
    // Add new customer from the file into the waiting line here
    thisSimulation->addToPending(this, this->getCurrTime(), this->getOrderID());

    // This check might cause problems, check if you'll remove it
    if (getOrderValue() > 0)
    {
        // Call the superclass 'processEvent' method to print the details common to all events
        Event::processEvent(thisSimulation);

        // Print the detail specific to just arrival events
        cout << "arrives. " << endl;

        // Start processing the next event in the queue if there is an available worker
        if (thisSimulation->getFreeEmp() > 0)
        {
            Event *tempPending = thisSimulation->getNextPending();

            // Get the next order in the pending orders list and start processing it
            Event *processNode = new PrepareEvent(tempPending, getCurrTime());

            // Insert the order in the pending events queue
            thisSimulation->addToQueue(processNode, processNode->getCurrTime(), processNode->getOrderID());
        }

        thisSimulation->readNextLine();
    }
}
