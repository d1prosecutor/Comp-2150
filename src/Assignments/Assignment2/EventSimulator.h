#pragma once

#include <sstream> //necessary for using stringstream
#include <fstream> //necessary to use ifstream (to open a file)
#include <string>

using namespace std;

class Event;
class PriorityQueue;

class EventSimulator
{
private:
    // Instance Variables
    string filename;
    float empWage;
    int numAddEmp;
    int numFreeEmp;
    int numStdHrs;
    int numWorkDays;
    ifstream inputFile;
    float initialProfit;
    PriorityQueue *eventQueue;
    PriorityQueue *pendingOrders;

public:
    // Constructors
    EventSimulator();
    EventSimulator(string, int);

    // Destructor
    ~EventSimulator();

    // Instance methods
    int getNumEmp();
    int getFreeEmp();
    void printStats();
    void incrFreeEmp();
    void decrFreeEmp();
    void readNextLine();
    void startSimulation();

    bool lineIsEmpty();
    bool queueIsEmpty();
    Event *getNextOrder();
    Event *getNextPending();
    void addToQueue(Event *, int, int);
    void addToPending(Event *, int, int);
    void updateProfit(float plusOrMinus);
    float calcFinalProfit(int);
    float calcCostOfBusiness(int);
};