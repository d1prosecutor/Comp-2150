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

    // Destructor
    ~PrepareEvent();

    // Instance methods
    int calcProcessTime(int);
    void processEvent(EventSimulator *thisSimulation) override;
};