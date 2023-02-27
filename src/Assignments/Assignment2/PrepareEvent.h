/***************************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 2
 *
 * REMARKS: Interface for the Prepare-Event Class
 **************************************************/
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

    // Instance methods
    int calcProcessTime(int) const;
    void processEvent(EventSimulator *thisSimulation) override;
};