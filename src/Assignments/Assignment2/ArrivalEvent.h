#pragma once

#include <string>
using namespace std;

#include "Event.h"

class ArrivalEvent : public Event
{
private:
    // Class variables
    static float initialProfit;

public:
    // Constructors
    ArrivalEvent();
    ArrivalEvent(int, string, int, int);

    // Class methods
    static void updateProfit(float);
    static float getInitialProfit();

    // Instance methods
    void processEvent() override;
};
