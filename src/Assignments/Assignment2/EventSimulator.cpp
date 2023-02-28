/***********************************************************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 2
 *
 * REMARKS: Implements the EventSimulator class which handles a simulation to be run
 *          and print results of the simulation
 ***********************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

#include "EventSimulator.h"
#include "ArrivalEvent.h"
#include "PriorityQueue.h"
#include "Order.h"

// Constructors
EventSimulator::EventSimulator() {}
EventSimulator::EventSimulator(string filename, int numAddEmp) : filename(filename), empWage(13.5), numAddEmp(numAddEmp),
																 numFreeEmp(numAddEmp + 1), numStdHrs(8), numWorkDays(0),
																 initialProfit(0.0f)

{
	eventQueue = new PriorityQueue();
	pendingOrders = new PriorityQueue();

	cout << "The filename is: " << filename << endl;
	cout << "The number of additional employees is: " << numAddEmp << endl;
}

// Destructor
EventSimulator::~EventSimulator()
{
	delete pendingOrders;
	delete eventQueue;
}

// Instance methods
/******************************************************************************
 * startSimulation
 *
 * PURPOSE: This Method runs the simulation by reading the input file and
 *           processing the events contained in it
 *******************************************************************************/
void EventSimulator::startSimulation()
{
	// Opening the file, reading one line (just the first one of the file here) and parsing it
	inputFile.open(filename); // opening the file for reading

	// cout << "The first line of the file is: " << endl;

	readNextLine(); // gets the next line from the file and saves it in 'line', if there is one

	// Process the events in the Event Queue
	while (!(queueIsEmpty()))
	{
		Event *nextEvent = getNextEvent();

		nextEvent->processEvent(this);

		// Update the total number of work days so far
		numWorkDays = ceil(nextEvent->getCurrTime() / (float)numStdHrs);

		// When done processing that event, free its memory
		// delete nextEvent;
	}

	// Print out the statistics
	printStats();
}

/******************************************************************************
 * readNextLine
 *
 * PURPOSE: This Method reads the next line from the input file, creates a new
 *          arrival event based on that line and adds it to the event queue
 *******************************************************************************/
void EventSimulator::readNextLine()
{
	string nextLine;

	if (getline(inputFile, nextLine)) // gets the next line from the file and saves it in 'line', if there is one
	{
		stringstream sst(nextLine); // stringstream allows us to parse the line token by token (kind of like a Scanner in Java)
		int time = 0;
		string customerType = "";
		int value = 0;

		sst >> time;		 // extracting the time
		sst >> customerType; // extracting the customerType
		sst >> value;		 // extracting the order value

		// Put the first line into the event queue
		Order *newOrder = new Order(time, customerType, value, time);
		Event *nextArrival = new ArrivalEvent(newOrder);
		addToQueue(nextArrival, time, nextArrival->getOrderID());

		// Update the profit with each new Order Created
		initialProfit += (value / 2.0f);
	}
}

/******************************************************************************
 * printStats
 *
 * PURPOSE: This Method prints out all the collected statistics about the simulation
 *******************************************************************************/
void EventSimulator::printStats() const
{
	// Now print out stats here
	// truncating the output to 2 decimal places
	cout << fixed << setprecision(2);

	cout << endl;
	cout << "########################" << endl;
	cout << "The simulation has ended." << endl;
	cout << "The number of additional workers was " << numAddEmp << "." << endl;
	cout << "The total number of work days was " << numWorkDays << "." << endl;
	cout << "The cost of additional workers was $" << calcCostOfBusiness(numAddEmp) << "." << endl;
	cout << "The total profit before paying workers was $" << initialProfit << "." << endl;
	cout << "The total profit when considering additional workers was $" << calcFinalProfit(numAddEmp) << "." << endl;
	cout << "########################" << endl;
	cout << endl;
}

/******************************************************************************
 * updateProfit
 *
 * PURPOSE: This Method updates the profit of the owner of the business after
 *           each discount is applied
 * INPUT PARAMETERS:
 *      plusOrMinus: The value (positive or negative) to be added to the profit
 *******************************************************************************/
void EventSimulator::updateProfit(float plusOrMinus)
{
	initialProfit += plusOrMinus;
}

/******************************************************************************
 * calcCostOfBusiness
 *
 * PURPOSE: This Method calculates and returns the total amount spent on the
 *          employees
 * INPUT PARAMETERS:
 *      numWorkers: The numebr of employees
 *******************************************************************************/
float EventSimulator::calcCostOfBusiness(int numWorkers) const
{
	// Calculate the cost of additional workers
	return (numWorkDays * numStdHrs * empWage * numWorkers) +
		   (numWorkDays * numWorkers);
}

/******************************************************************************
 * calcFinalProfit
 *
 * PURPOSE: This Method calculates and returns the owner's final profit after
 *          expenditures on the employees
 * INPUT PARAMETERS:
 *      numWorkers: The number of employees
 *******************************************************************************/
float EventSimulator::calcFinalProfit(int numWorkers) const
{
	return initialProfit - calcCostOfBusiness(numWorkers);
}

/******************************************************************************
 * addToQueue
 *
 * PURPOSE: This Method adds the given event to the event queue
 *
 * INPUT PARAMETERS:
 *      newEvent: The new event to be added to the queue
 *      timePriority: The current time in the simulation
 *      orderPriority: The orderId of the event given
 *******************************************************************************/
void EventSimulator::addToQueue(Event *newEvent, int timePriority, int orderPriority)
{
	eventQueue->enqueue(newEvent, timePriority, orderPriority);
}

/******************************************************************************
 * addToPending
 *
 * PURPOSE: This Method adds an arrival event to the pending line of arrival orders
 *
 * INPUT PARAMETERS:
 *      newEvent: The new event to be added to the queue
 *      customerType: The customer type (primero vs standard)
 *      timePriority: The current time in the simulation
 *      orderPriority: The orderId of the event given
 *******************************************************************************/
void EventSimulator::addToPending(Event *newEvent, string customerType, int timePriority, int orderPriority)
{
	pendingOrders->addToLine(newEvent, customerType, timePriority, orderPriority);
}

/******************************************************************************
 * getNextEvent
 *
 * PURPOSE: This Method gets the next event from the eventQueue
 *******************************************************************************/
Event *EventSimulator::getNextEvent() const
{
	return eventQueue->dequeue();
}

/******************************************************************************
 * getNextPending
 *
 * PURPOSE: This Method gets the next arrival event from the pending orders line
 *******************************************************************************/
Event *EventSimulator::getNextPending() const
{
	return pendingOrders->dequeue();
}

bool EventSimulator::queueIsEmpty() const
{
	return eventQueue->isEmpty();
}

bool EventSimulator::pendingIsEmpty() const
{
	return pendingOrders->isEmpty();
}

// Accessors
int EventSimulator::getFreeEmp() const
{
	return numFreeEmp;
}

// Mutators
void EventSimulator::incrFreeEmp()
{
	numFreeEmp++;
}

void EventSimulator::decrFreeEmp()
{
	numFreeEmp--;
}
