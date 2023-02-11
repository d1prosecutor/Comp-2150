#pragma once

#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)
#include <string>

using namespace std;

class EventSimulator
{
private:
    static int numAddEmp;
    static int numFreeEmp;
    static string filename;
    static ifstream inputFile;

public:
    // Constructors
    EventSimulator();
    EventSimulator(string, int);

    // Instance methods
    static int getNumEmp();
    static int getFreeEmp();
    static int incrFreeEmp();
    static int decrFreeEmp();
    static void printStats();
    static int hasNextLine();
    static void readNextLine();
    static void startSimulation();
};