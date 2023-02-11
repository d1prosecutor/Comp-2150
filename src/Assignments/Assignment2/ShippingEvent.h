#pragma once

#include "Event.h"

class ShippingEvent : public Event
{
private:
    int arrivalTime;

public:
    // Constructors
    ShippingEvent();
    ShippingEvent(Event *, int, int);

    // instance methods
    float calcDiscount(int);
    void processEvent() override;
};