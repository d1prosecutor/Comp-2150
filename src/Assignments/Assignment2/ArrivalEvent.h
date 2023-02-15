#pragma once

#include <string>
using namespace std;
#include "Event.h"

class Order;
class ArrivalEvent : public Event
{
public:
    // Constructors
    ArrivalEvent();
    ArrivalEvent(Order *);

    // Instance methods
    ~ArrivalEvent();
    void processEvent(EventSimulator *thisSimulation) override;
};
