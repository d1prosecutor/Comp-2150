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
const int Order::getCurrTime() const
{
    return currTime;
}

void Order::setCurrTime(int newTime)
{
    currTime = newTime;
}

const int Order::getArrivalTime() const
{
    return arrivalTime;
}

const string Order::getCustomerType() const
{
    return customerType;
}

const int Order::getOrderValue() const
{
    return orderValue;
}

const int Order::getOrderID() const
{
    return orderID;
}