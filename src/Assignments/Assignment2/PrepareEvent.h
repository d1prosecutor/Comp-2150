#pragma once

#include "Event.h"
class Event;

class PrepareEvent : public Event
{
public:
    // Constructors
    PrepareEvent();
    PrepareEvent(Event *, int, int);

    // Instance methods
    ~PrepareEvent();
    int calcProcessTime(int);
    void processEvent() override;
};