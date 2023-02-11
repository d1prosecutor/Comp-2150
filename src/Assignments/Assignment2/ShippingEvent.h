#pragma once

#include "Event.h"

class ShippingEvent : public Event
{
public:
    // Constructors
    ShippingEvent();
    ShippingEvent(Event *, int, int);

    // instance methods
    float calcDiscount(int);
    void printPrimeroDiscount();
    void printStandardDiscount();
    void processEvent() override;
};