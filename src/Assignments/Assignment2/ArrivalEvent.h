#pragma once

#include "Event.h"
#include <string>

class ArrivalEvent : public Event
{
public:
    // Constructors
    ArrivalEvent();
    ArrivalEvent(Event *);
    ArrivalEvent(int, string, int);

    // Instance methods
    void processEvent() override;
};
