/****************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 2
 *
 * REMARKS: Interface for the Order Class
 ****************************************/
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
    int getOrderID() const;
    int getCurrTime() const;
    int getOrderValue() const;
    int getArrivalTime() const;
    string getCustomerType() const;

    // Mutators
    void setCurrTime(int);
};