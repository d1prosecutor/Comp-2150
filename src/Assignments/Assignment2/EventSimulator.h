/*************************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 2
 *
 * REMARKS: Interface for the EventSimulator Class
 ************************************************/
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
    void incrFreeEmp();
    void decrFreeEmp();
    void readNextLine();
    void startSimulation();
    void printStats() const;
    bool queueIsEmpty() const;
    bool pendingIsEmpty() const;
    Event *getNextEvent() const;
    Event *getNextPending() const;
    float calcFinalProfit(int) const;
    void addToQueue(Event *, int, int);
    float calcCostOfBusiness(int) const;
    void addToPending(Event *, int, int);
    void updateProfit(float plusOrMinus);
};