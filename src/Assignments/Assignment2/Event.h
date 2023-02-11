#pragma once

#include <string>
using namespace std;

class PriorityQueue;

class Event
{
private:
    static int ID;
    static int numWorkDays;

protected:
    // Class Variables
    static int numWorkers;
    static int numFreeWorkers;
    static PriorityQueue *eventQueue;
    static PriorityQueue *pendingOrders;

    // Instance Variables
    int orderID;
    int currTime;
    int orderValue;
    int arrivalTime;
    string customerType;

public:
    // Constructors
    Event();
    Event(Event *, int, int);
    Event(int, string, int, int);

    // Class methods
    static void addToQueue(Event *);
    static void addToPending(Event *);
    static int getNumFreeWorkers();
    static Event *getNextPending();
    static Event *getNextEvent();
    static bool queueIsEmpty();
    static bool lineIsEmpty();
    static int getNumWorkDays();
    static float calcFinalProfit();
    static float calcCostOfBusiness();
    static void calcNumWorkDays(int);

    // Instance methods
    int getCurrTime();
    int getArrivalTime();
    string getCustomerType();
    int getOrderValue();
    int getOrderID();
    virtual void processEvent();
};
