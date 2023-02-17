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

    // Accessors
    int getArrTime() const;
    int getOrderID() const;
    int getCurrTime() const;
    int getOrderValue() const;
    string getCustomerType() const;

    // Instance methods
    virtual void processEvent(EventSimulator *);
};
