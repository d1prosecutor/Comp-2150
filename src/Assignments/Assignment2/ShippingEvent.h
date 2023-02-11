#pragma once

#include "Event.h"
using namespace std;

class ShippingEvent : public Event
{
private:
    int arrivalTime;

public:
    // Constructors
    ShippingEvent();
    ShippingEvent(Event *, int);

    // instance methods
    float calcDiscount(int);
    void processEvent() override;
};