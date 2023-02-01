package Assignments.Assignment1;

/***********************************************************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 1
 *
 * REMARKS: Implements the Activity class (abstract superclass) which holds all the
 *          activity subclasses together and activates polymorphism.
 ***********************************************************************************/

import java.time.Duration;
import java.time.LocalDate;

public abstract class Activity
{
    //Static variables
    private static ActivityList allActivitiesList = new ActivityList();
    private static Duration TOTAL_TIME = Duration.ZERO;

    //Instance variables (Fields)
    private String name;
    private String location;
    private LocalDate date;
    private Duration duration;

    //Constructors
    public Activity()
    {
    }

    public Activity(String name, String location, LocalDate date, Duration duration)
    {
        this.name = name;
        this.location = location;
        this.date = date;
        this.duration = duration;
    }

    //Instance Methods

    /******************************************************************************
     * trackActivity
     *
     * PURPOSE: This Method adds the particular object(instance) being worked on to
     *          the list of all activities
     *
     * INPUT PARAMETERS:
     *      newActivity: The new Activity to be tracked
     *******************************************************************************/
    public void trackActivity(Activity newActivity)
    {
        allActivitiesList.addActivity(newActivity);

        //Keep track of the duration (time) spent in all activities
        TOTAL_TIME = TOTAL_TIME.plus(newActivity.duration);
    }

    /******************************************************************************
     * queryBetweenDates
     *
     * PURPOSE: This Method prints all activities occurring between two specified
     *          dates
     *
     * INPUT PARAMETERS:
     *      The two parameters are the dates that specify the range of activities
     *******************************************************************************/
    public static void queryBetweenDates(LocalDate firstDate, LocalDate lastDate)
    {
        System.out.println("\n>>> Querying activity time between " + firstDate + " and " + lastDate + ":");
        allActivitiesList.printBetweenDates(firstDate, lastDate);
    }

    /*******************************************************************************
     * print
     *
     * PURPOSE: This method prints out the details of all activities of all type
     *          stored in the List
     *******************************************************************************/
    public static void print()
    {
        System.out.println("\n>>> Querying total activity time: ");
        System.out.println(">>> " + TOTAL_TIME.toHours() + " hour(s) and " +
                TOTAL_TIME.toMinutesPart() + " minute(s).");
        System.out.println("========== Activities ==========");

        allActivitiesList.print();
    }

    /******************************************************************************
     * compareTo
     *
     * PURPOSE: This method is used to check if two activities might be the same by
     *          checking if all the fields common to both activities are the same
     *
     *  OUTPUT PARAMETERS:
     *          The method returns true if the two activities have their common fields
     *          being the same
     *******************************************************************************/
    public boolean compareTo(Activity thisActivity)
    {
        return (name.equalsIgnoreCase(thisActivity.name) && location.equalsIgnoreCase(thisActivity.location) &&
                date.isEqual(thisActivity.date) && duration.equals(thisActivity.duration));
    }

    /******************************************************************************
     * query
     *
     * PURPOSE: This Method is overridden by the subclasses of Activity to print the
     *          activities of a specific type
     *******************************************************************************/
    public abstract void query();

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
}
