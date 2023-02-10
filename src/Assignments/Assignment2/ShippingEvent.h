#pragma once

#include "Event.h"

class ShippingEvent : public Event
{
private:
    int arrivalTime;

public:
    // Constructors
    ShippingEvent();
    ShippingEvent(Event *, int);

    // instance methods
    void processEvent() override;
};