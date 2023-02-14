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
    ShippingEvent(Event *, int, int);

    // instance methods
    ~ShippingEvent();
    float calcDiscount(int);
    void printPrimeroDiscount();
    void printStandardDiscount();
    void processEvent() override;
};