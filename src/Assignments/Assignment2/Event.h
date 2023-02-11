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
    static PriorityQueue *eventQueue;
    static PriorityQueue *pendingOrders;

    // Instance Variables
    int currTime;
    string customerType;
    int orderValue;
    int arrivalTime;
    int orderID;

public:
    // Constructors
    Event();
    Event(Event *, int, int);
    Event(int, string, int, int);

    // Class methods
    static bool lineIsEmpty();
    static bool queueIsEmpty();
    static int getNumWorkDays();
    static Event *getNextOrder();
    static Event *getNextPending();
    static int getNumFreeWorkers();
    static void addToQueue(Event *);
    static void calcNumWorkDays(int);
    static void addToPending(Event *);
    static float calcFinalProfit(int);
    static float calcCostOfBusiness(int);

    // Instance methods
    int getOrderID();
    int getCurrTime();
    int getOrderValue();
    int getArrivalTime();
    string getCustomerType();
    virtual void processEvent();
};
