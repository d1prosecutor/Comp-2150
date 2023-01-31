package Assignments.Assignment1;
/***************************************************************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 1
 *
 * REMARKS: Implements the Swim class, which is a type of Activity(superclass).
 ***************************************************************************************/

import java.time.Duration;
import java.time.LocalDate;

public class Swim extends Activity
{
    //Static variables
    private static Duration totalTime = Duration.ZERO;

    private static ActivityList swimmingList = new ActivityList();

    //Instance variables
    private int numLaps;
    private int lapLength;

    //Constructors
    public Swim()
    {
    }

    public Swim(String name, String location, LocalDate date,
                Duration duration, int numLaps, int lapLength)
    {
        //Call the super constructor to initialize the variables common to all the subclasses
        super(name, location, date, duration);

        //initialize the variables special to this an instance of this class
        this.numLaps = numLaps;
        this.lapLength = lapLength;

        //Track and print out details of the activity if it doesn't already exist
        if (!swimmingList.searchForActivity(this))
        {
            System.out.print("Adding Activity: ");

            //Print the details of the activity being added
            query();

            trackActivity(this);
        }
    }

    /******************************************************************************
     * trackActivity
     *
     * PURPOSE: This Method adds the particular object(instance) being worked on to
     *          the list of all activities (using the super method) and the list containing
     *          all Swimming activities
     *
     * INPUT PARAMETERS:
     *      newActivity: The new Activity to be tracked
     *******************************************************************************/
    @Override
    public void trackActivity(Activity newActivity)
    {
        //add the new activity to the two lists
        super.trackActivity(newActivity);
        swimmingList.addActivity(newActivity);

        //Keep track of the total duration of all Swimming activities to avoid repeated calculation
        totalTime = totalTime.plus(getDuration());
    }

    /******************************************************************************
     * calcPace
     *
     * PURPOSE: This method calculates the distance in kilometers using the number of
     *          laps and the length of each lap
     *
     *  OUTPUT PARAMETERS:
     *          The method returns the calculated distance (in kilometers)
     *******************************************************************************/
    private float calcDistance()
    {
        return (float) ((lapLength / 1000.0) * numLaps);
    }

    /******************************************************************************
     * calcPace
     *
     * PURPOSE: This method calculates the pace using the duration (in minutes)
     *          and the distance (in km) gotten from the calcDistance method.
     *
     *  OUTPUT PARAMETERS:
     *          The method returns the calculated pace (in min/km)
     *******************************************************************************/
    private float calcPace()
    {
        return getDuration().toMinutes() / calcDistance();
    }

    /*******************************************************************************
     * print
     *
     * PURPOSE: This method prints out the details of all activities of type 'Swimming'
     *          stored in the List
     *******************************************************************************/
    public static void print()
    {
        //Print out the banner and the total time across all Swimming activities
        System.out.println("\n>>> Querying activities of type SWIMMING");
        System.out.println(">>> " + totalTime.toHoursPart() + " hour(s) and " +
                totalTime.toMinutesPart() + " minute(s).");
        System.out.println("========== Activities ==========");

        //Print the details of the activity being added
        swimmingList.print();
    }

    /******************************************************************************
     * query
     *
     * PURPOSE: This method is a works in tandem with the print method and is used
     *          to print out the details of a single Swimming activity
     *******************************************************************************/
    @Override
    public void query()
    {
        //Convert the pace (in minutes/km) to min:secs min/km format
        float pace = calcPace();
        int paceHours = ((int) pace); // get the whole number part of the minutes from the pace
        int paceMinutes = (int) ((calcPace() * 60) % 60); //convert the decimal part of the pace to seconds


        //Print out the details of the Swimming activity
        System.out.println("[" + getDate() + "] Swimming: " + getName() + " at " + getLocation());
        System.out.println("duration: " + this.getDuration().toHoursPart() + " hour(s) and " +
                getDuration().toMinutesPart() + " minutes(s);");
        System.out.println("number of laps: " + numLaps + " laps;");
        System.out.println("lapLength: " + lapLength + "m");
        System.out.format("average pace: %d:%02d min/km\n\n",
                paceHours, paceMinutes);
    }

    /******************************************************************************
     * compareTo
     *
     * PURPOSE: This method is used to check if two Swimming activities are the same by
     *          checking if all the fields of both activities are the same
     *
     *  OUTPUT PARAMETERS:
     *          The method returns true if the two activities are the same and false
     *          otherwise
     *******************************************************************************/
    public boolean compareTo(Activity thisActivity)
    {
        if (thisActivity instanceof Swim)
        {
            return (super.compareTo(thisActivity) && numLaps == ((Swim) thisActivity).numLaps &&
                    lapLength == ((Swim) thisActivity).lapLength);
        }
        return false;
    }
}
