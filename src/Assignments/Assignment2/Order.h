#pragma once

#include <string>
using namespace std;

class Order
{
private:
    // Class variables
    static int ID;

    // Instance Variables
    int currTime;
    string customerType;
    int orderValue;
    int arrivalTime;
    int orderID;

public:
    // Constructors
    Order();
    Order(int, string, int, int);

    // Accessors
    const int getOrderID() const;
    const int getCurrTime() const;
    const int getOrderValue() const;
    const int getArrivalTime() const;
    const string getCustomerType() const;

    // Mutators
    void setCurrTime(int);
};