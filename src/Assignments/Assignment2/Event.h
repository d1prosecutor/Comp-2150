#pragma once

#include <string>
using namespace std;

class Order;
class EventSimulator;

class Event
{
private:
    // Class variables
    static int numWorkDays;

    // Instance variables
    Order *thisOrder;

public:
    // Constructors
    Event();
    Event(Order *);
    Event(Event *, int);

    // Destructor
    virtual ~Event() = 0;

    // Class methods
    static int getNumWorkDays();
    static void calcNumWorkDays(int);

    // Instance methods
    const int getArrTime();
    const int getOrderID();
    const int getCurrTime();
    const int getOrderValue();
    const string getCustomerType();
    virtual void processEvent(EventSimulator *);
};
