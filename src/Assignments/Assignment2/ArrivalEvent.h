/***************************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 2
 *
 * REMARKS: Interface for the Arrival-Event Class
 **************************************************/
#pragma once

#include <string>
using namespace std;
#include "Event.h"

class Order;
class ArrivalEvent : public Event
{
public:
    // Constructors
    ArrivalEvent();
    ArrivalEvent(Order *);

    // Destructor
    ~ArrivalEvent();
    
    // Instance methods
    void processEvent(EventSimulator *thisSimulation) override;
};
