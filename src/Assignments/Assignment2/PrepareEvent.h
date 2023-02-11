#pragma once

#include "Event.h"
class Event;

class PrepareEvent : public Event
{
private:
    int processTime;

public:
    // Constructors
    PrepareEvent();
    PrepareEvent(Event *, int);

    // Instance methods
    int calcProcessTime(int);
    void processEvent() override;
};