/***********************************************************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 2
 *
 * REMARKS: Implements the Order class which acts as a record (holding the attributes
 *          of each order together), but provides accessors and mutators for those
 *          attributes
 ***********************************************************************************/
#include "Order.h"

// Initializing class Variables
int Order::ID = 0;

// Constructors
Order::Order() {}

Order::Order(int currTime, string customerType, int orderValue, int arrivalTime) : currTime(currTime),
                                                                                   customerType(customerType),
                                                                                   orderValue(orderValue),
                                                                                   arrivalTime(arrivalTime),
                                                                                   orderID(++Order::ID) {}

// Accessors
 int Order::getCurrTime() const
{
    return currTime;
}

 int Order::getArrivalTime() const
{
    return arrivalTime;
}

 string Order::getCustomerType() const
{
    return customerType;
}

 int Order::getOrderValue() const
{
    return orderValue;
}

 int Order::getOrderID() const
{
    return orderID;
}

// Mutators
void Order::setCurrTime(int newTime)
{
    currTime = newTime;
}