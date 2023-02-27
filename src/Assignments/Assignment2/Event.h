/*****************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 2
 *
 * REMARKS: Interface for the Event Class
 ****************************************/
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
    Order *getOrder() const;
    int getCurrTime() const;
    int getOrderValue() const;
    string getCustomerType() const;

    // Instance methods
    virtual void processEvent(EventSimulator *);
};
