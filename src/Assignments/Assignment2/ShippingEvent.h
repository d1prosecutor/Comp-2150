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
    float calcDiscount(int);

    // instance methods
    void printPrimeroDiscount(EventSimulator *);
    void printStandardDiscount(EventSimulator *);
    void processEvent(EventSimulator *thisSimulation) override;
};