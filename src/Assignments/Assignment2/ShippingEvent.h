/***************************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 2
 *
 * REMARKS: Interface for the Shipping-Event Class
 **************************************************/
#pragma once

#include "Event.h"

class ShippingEvent : public Event
{
private:
    static float discount;
    static int primeroLateShip;
    static int standardLateShip;

public:
    // Constructors
    ShippingEvent();
    ShippingEvent(Event *, int);

    // Destructor
    ~ShippingEvent();

    // instance methods
    float calcDiscount(int) const;
    void printPrimeroDiscount(EventSimulator *) const;
    void printStandardDiscount(EventSimulator *) const;
    void processEvent(EventSimulator *thisSimulation) override;
};