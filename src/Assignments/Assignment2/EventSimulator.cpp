#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)
#include <string>
#include <iostream>

#include "PriorityQueue.h"
#include "Event.h"
#include "ArrivalEvent.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "USAGE: FileReadingExample.exe filename numAdditionalEmp" << endl;
		cout << "where numAdditionalEmp is an integer >= 0." << endl;
		return 0;
	}

	string filename = argv[1];
	int numAddEmp = stoi(argv[2]);

	cout << "The filename is: " << filename << endl;
	cout << "The number of additional employees is: " << numAddEmp << endl;

	//
	// Opening the file, reading one line (just the first one of the file here) and parsing it
	//
	ifstream inputFile;
	inputFile.open(filename); // opening the file for reading
	string line;

	cout << "The first line of the file is: " << endl;

	if (getline(inputFile, line)) // gets the next line from the file and saves it in 'line', if there is one
	{
		stringstream sst(line); // stringstream allows us to parse the line token by token (kind of like a Scanner in Java)
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

		while (!(Event::queueIsEmpty()))
		{
			Event *nextEvent = Event::getNextEvent();
			nextEvent->processEvent();
		}

		// Now print out stats here
	}
}
