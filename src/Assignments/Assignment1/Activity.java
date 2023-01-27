package Assignments.Assignment1;

import java.time.Duration;
import java.time.LocalDate;

public abstract class Activity
{
    public static ActivityList allActivities = new ActivityList();
    //track the total time across all activities
    private static Duration TOTAL_TIME = Duration.ZERO;

    //Instance variables (Fields)
    private String name;
    private String location;
    private LocalDate date;
    private Duration duration;

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
        TOTAL_TIME = TOTAL_TIME.plus(newActivity.duration);
    }

    public static void queryBetweenDates(LocalDate firstDate, LocalDate lastDate)
    {
        System.out.println(">>> Querying activity time between " + firstDate + " and " + lastDate + ":");
        allActivities.printBetweenDates(firstDate, lastDate);
    }

    protected String getName()
    {
        return name;
    }

    protected LocalDate getDate()
    {
        return date;
    }

    protected Duration getDuration()
    {
        return duration;
    }

    protected String getLocation()
    {
        return location;
    }

    public static void print()
    {
        System.out.println(">>> Querying total activity time: ");
        System.out.println(">>> " + TOTAL_TIME.toHoursPart() + " hours and " +
                TOTAL_TIME.toMinutesPart() + " minutes.");
        System.out.println("========== Activities ==========");

        allActivities.print();
    }

    public abstract void query();

    public boolean compareTo(Activity thisActivity)
    {
        return (name.equals(thisActivity.name) && location.equals(thisActivity.location) &&
                date.isEqual(thisActivity.date) && duration.equals(thisActivity.duration));
    }
}
