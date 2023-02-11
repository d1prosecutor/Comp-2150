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
    PrepareEvent(Event *);

    // Instance methods
    void processEvent() override;
    int calcProcessTime(int);
};