#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)
#include <iostream>

#include "ArrivalEvent.h"
#include "PrepareEvent.h"
#include "PriorityQueue.h"
#include "EventSimulator.h"

using namespace std;

// Initialize Class variables
float ArrivalEvent::initialProfit = 0.0f;

// Constructors
ArrivalEvent::ArrivalEvent() {}

ArrivalEvent::ArrivalEvent(int time, string customerType, int orderValue, int arrivalTime)
    : Event(time, customerType, orderValue, arrivalTime)
{
    initialProfit += (orderValue / 2.0f);
}

// Instance methods
void ArrivalEvent::processEvent()
{
    // Add new customer from the file into the waiting line here
    Event::addToPending(this);

    // This check might cause problems, check if you'll remove it
    if (orderValue > 0)
    {
        // Call the superclass 'processEvent' method to print the details common to all events
        Event::processEvent();

        // Print the detail specific to just arrival events
        cout << "arrives. " << endl;

        // Start processing the next event in the queue if there is an available worker
        if (Event::getNumFreeWorkers() > 0)
        {
            // Get the next order in the pending orders list and start processing it
            Event *processNode = new PrepareEvent(Event::getNextPending(), currTime, arrivalTime);

            // Insert the order in the pending events queue
            Event::addToQueue(processNode);
        }

        if (EventSimulator::hasNextLine() != EOF)
        {
            EventSimulator::readNextLine();
        }
    }
}

// Class Methods
float ArrivalEvent::getInitialProfit()
{
    return ArrivalEvent::initialProfit;
}

void ArrivalEvent::updateProfit(float plusOrMinus)
{
    ArrivalEvent::initialProfit += plusOrMinus;
}
