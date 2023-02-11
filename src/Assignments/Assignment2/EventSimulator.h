#pragma once

#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)
#include <string>

using namespace std;

class EventSimulator
{
private:
    static int numAddEmp;
    static string filename;
    static ifstream inputFile;

public:
    // Constructors
    EventSimulator();
    EventSimulator(string, int);

    // Instance methods
    static int getNumEmp();
    static void printStats();
    static int hasNextLine();
    static void readNextLine();
    static void startSimulation();
};