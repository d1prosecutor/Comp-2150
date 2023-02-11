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
    ArrivalEvent(Event *);
    ArrivalEvent(int, string, int);

    // Class methods
    static float getinitialProfit();
    static void updateProfit(float);

    // Instance methods
    void processEvent() override;
};
