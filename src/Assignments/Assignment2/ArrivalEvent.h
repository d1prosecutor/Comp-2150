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
    static float getInitialProfit();
    static void updateProfit(float);

    // Instance methods
    void processEvent() override;
};
