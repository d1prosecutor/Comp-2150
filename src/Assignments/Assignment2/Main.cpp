/***********************************************************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 2
 *
 * REMARKS: Contains the main function which creates and runs a new Simulation with
 *          data recevied when the program is run
 ***********************************************************************************/
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
    EventSimulator newSimulation(filename, numAddEmp);
    newSimulation.startSimulation();
    // EventSimulator *newSimulation = new EventSimulator(filename, numAddEmp);
    // newSimulation->startSimulation();

    cout << endl
         << "End of Program" << endl;
    return 0;
}