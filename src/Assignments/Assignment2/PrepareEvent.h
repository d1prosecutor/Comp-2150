#pragma once
#include "Event.h"
class Event;
using namespace std;

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