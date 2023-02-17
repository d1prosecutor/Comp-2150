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

    // Destructor
    // ~ArrivalEvent();

    // Instance methods
    void processEvent(EventSimulator *thisSimulation) override;
};
