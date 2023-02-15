#include <iostream>
#include "EventSimulator.h"

using namespace std;
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "USAGE: FileReadingExample.exe filename numAdditionalEmp" << endl;
        cout << "where numAdditionalEmp is an integer >= 0." << endl;
        return 0;
    }

    // Parse the arguments required for the file reading
    string filename = argv[1];
    int numAddEmp = stoi(argv[2]);

    // Create a new Simulation and start the simulation
    // EventSimulator *newSimulation = new EventSimulator(filename, numAddEmp);
    EventSimulator *newSimulation = new EventSimulator(filename, numAddEmp);

    newSimulation->startSimulation();

    cout << endl
         << "End of Program" << endl;
    return 0;
}