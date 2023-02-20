#pragma once

#include "Event.h"
class Event;

class PrepareEvent : public Event
{
private:
    static int pricePerHour;

public:
    // Constructors
    PrepareEvent();
    PrepareEvent(Event *, int);

    // Instance methods
    int calcProcessTime(int) const;
    void processEvent(EventSimulator *thisSimulation) override;
};