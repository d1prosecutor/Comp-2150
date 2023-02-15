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

// Instance Methods
const int Order::getCurrTime()
{
    return currTime;
}

void Order::setCurrTime(int newTime)
{
    currTime = newTime;
}

const int Order::getArrivalTime()
{
    return arrivalTime;
}

const string Order::getCustomerType()
{
    return customerType;
}

const int Order::getOrderValue()
{
    return orderValue;
}

const int Order::getOrderID()
{
    return orderID;
}