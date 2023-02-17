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

    // Accessors
    int getFreeEmp() const;

    // Instance methods
    bool lineIsEmpty() const;
    void incrFreeEmp();
    void decrFreeEmp();
    bool queueIsEmpty() const;
    void readNextLine();
    void startSimulation();
    void printStats() const;
    Event *getNextOrder() const;
    Event *getNextPending() const;
    float calcFinalProfit(int) const;
    void addToQueue(Event *, int, int);
    float calcCostOfBusiness(int) const;
    void addToPending(Event *, int, int);
    void updateProfit(float plusOrMinus);
};