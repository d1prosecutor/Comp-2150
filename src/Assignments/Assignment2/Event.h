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
    static int numFreeWorkers;
    static PriorityQueue *eventQueue;
    static PriorityQueue *pendingOrders;
    // Instance Variables
    int time;
    string customerType;
    int orderValue;
    int orderID;

public:
    // Constructors
    Event();
    Event(Event *, int);
    Event(int, string, int);

    // Class methods
    static void addToQueue(Event *);
    static void addToPending(Event *);
    static int getNumFreeWorkers();
    static Event *getNextPending();
    static Event *getNextEvent();
    static bool queueIsEmpty();
    static bool lineIsEmpty();
    static int getNumWorkDays();

    // Instance methods
    int getTime();
    string getCustomerType();
    int getOrderValue();
    void setTime(int);
    virtual void processEvent();
};
