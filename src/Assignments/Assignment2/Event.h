#pragma once

#include <string>
using namespace std;

class Order;
class EventSimulator;

class Event
{
private:
    // Instance variables
    Order *thisOrder;

public:
    // Constructors
    Event();
    Event(Order *);
    Event(Event *, int);

    // Destructor
    virtual ~Event() = 0;

    // Instance methods
    const int getArrTime();
    const int getOrderID();
    const int getCurrTime();
    const int getOrderValue();
    const string getCustomerType();
    virtual void processEvent(EventSimulator *);
};
