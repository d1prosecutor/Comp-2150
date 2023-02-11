#include <iostream>

using namespace std;

#include "EventSimulator.h"
#include "Event.h"
#include "ArrivalEvent.h"

// Initializing Class Variables
int EventSimulator::numAddEmp;
string EventSimulator::filename;
ifstream EventSimulator::inputFile;

// Constructors
EventSimulator::EventSimulator() {}
EventSimulator::EventSimulator(string filename, int numAddEmp)
{
	EventSimulator::numAddEmp = numAddEmp;
	EventSimulator::filename = filename;
	cout << "The filename is: " << filename << endl;
	cout << "The number of additional employees is: " << numAddEmp << endl;
}

// Instance method
void EventSimulator::startSimulation()
{

	//
	// Opening the file, reading one line (just the first one of the file here) and parsing it
	//
	inputFile.open(filename); // opening the file for reading

	cout << "The first line of the file is: " << endl;

	if (hasNextLine() != EOF) // gets the next line from the file and saves it in 'line', if there is one
	{
		readNextLine();

		// Process the events in the Event Queue
		while (!(Event::queueIsEmpty()))
		{
			Event *nextEvent = Event::getNextEvent();
			nextEvent->processEvent();
		}
	}

	// Print out the statistics
	printStats();
}

int EventSimulator::hasNextLine()
{
	return (inputFile.peek());
}

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

		// To show that we parsed all the relevant information:
		cout << "time=" << time << " customerType=" << customerType << " value=" << value << endl;

		// Put the first line into the event queue
		Event *firstArrival = new ArrivalEvent(time, customerType, value);
		Event::addToQueue(firstArrival);
	}
}

void EventSimulator::printStats()
{
	// Now print out stats here
	cout << endl;
	cout << "################################" << endl;
	cout << "The simulation has ended." << endl;
	cout << "The number of additional workers was " << numAddEmp << "." << endl;
	cout << "The total number of work days was " << Event::getNumWorkDays() << "." << endl;
	cout << "The cost of additional workers was " << calcCostOfBusiness() << "." << endl;
	cout << "The total profit before paying workers was " << ArrivalEvent::getinitialProfit() << "." << endl;
	cout << "The total profit when considering additional workers was " << calcFinalProfit() << "." << endl;
	cout << "################################" << endl;
	cout << endl;
}

float EventSimulator::calcCostOfBusiness()
{
	// Calculate the cost of additional workers
	float empWage = 13.50;
	int numStdHrs = 8;
	return (Event::getNumWorkDays() * numStdHrs * empWage * numAddEmp) + (Event::getNumWorkDays() * numAddEmp);
}

float EventSimulator::calcFinalProfit()
{
	return ArrivalEvent::getinitialProfit() - calcCostOfBusiness();
}