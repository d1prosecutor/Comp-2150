#pragma once

#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)

#include <string>
using namespace std;

class EventSimulator
{
private:
    int numAddEmp;
    string filename;
    ifstream inputFile;

public:
    // Constructors
    EventSimulator();
    EventSimulator(string, int);

    // Instance methods
    void printStats();
    void startSimulation();
    void readLine();
    float calcFinalProfit();
    int hasNextLine();
    float calcCostOfBusiness();
};