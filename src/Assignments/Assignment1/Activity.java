package Assignments.Assignment1;

import java.time.Duration;
import java.time.LocalDate;

public abstract class Activity
{
    public static ActivityList allActivities = new ActivityList();
    //track the total time across all activities
    private static Duration TOTAL_TIME = Duration.ZERO;

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

        System.out.print("Adding Activity: ");
    }

    //Instance Methods


    //Update the list of all activities after creating each activity
    //Is called from the child classes
    public void trackActivity(Activity newActivity)
    {
        allActivities.addActivity(newActivity);

        //Keep track of the duration (time) spent in all activities
        TOTAL_TIME = TOTAL_TIME.plus(newActivity.duration);
    }

    private static int timeBetweenDates(LocalDate firstDate, LocalDate lastDate)
    {
        return allActivities.calculateTimeBetweenDates(firstDate, lastDate);
    }


    public LocalDate getDate()
    {
        return date;
    }

    public Duration getDuration()
    {
        return duration;
    }

    public void print()
    {
        System.out.println(">>> Querying total activity time: ");
        System.out.println(">>> " + TOTAL_TIME.toHoursPart() + " hours and " +
                TOTAL_TIME.toMinutesPart() + " minutes.");
        System.out.println("========== Activities ==========");

        allActivities.print();
    }

    public void query()
    {
        System.out.println("[" + date + "] " + "Running: " + this.name + " at " + this.location);
    }
}
