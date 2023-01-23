package Assignments.Assignment1;

import java.time.Duration;
import java.time.LocalDate;

public abstract class Activity
{
    public static ActivityList allActivities = new ActivityList();
    private static int TOTAL_TIME_SPENT_IN_ALL = 0;

    //Instance variables (Fields)
    public String name;
    public String location;

    public LocalDate date;
    public Duration duration;

    //Constructor
    public Activity(String name, String location, LocalDate date, Duration duration)
    {
        this.name = name;
        this.location = location;
        this.date = date;
        this.duration = duration;
    }

    //Instance Methods


    //Update the list of all activities after creating each activity
    //Is called from the child classes
    public void trackActivity(Activity newActivity)
    {
        allActivities.addActivity(newActivity);

        //Keep track of the duration (time) spent in all activities
        TOTAL_TIME_SPENT_IN_ALL += duration.toHours();
    }

    private boolean QueryActivity()
    {
        return false;
    }

    private static int timeBetweenDates(LocalDate firstDate, LocalDate lastDate)
    {
        return allActivities.calculateTimeBetweenDates(firstDate, lastDate);
    }

    public abstract void print();

    public LocalDate getDate()
    {
        return date;
    }

    public Duration getDuration()
    {
        return duration;
    }
}
