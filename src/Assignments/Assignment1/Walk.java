package Assignments.Assignment1;
/***************************************************************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 1
 *
 * REMARKS: Implements the Walk class, which is a type of Activity(superclass).
 ***************************************************************************************/

import java.time.Duration;
import java.time.LocalDate;

public class Walk extends Activity
{
    //Static variables
    private static Duration totalTime = Duration.ZERO;

    private static ActivityList walkingList = new ActivityList();

    //Instance variables
    private int distance;
    private int elevation;

    //Constructors

    public Walk()
    {
    }


    public Walk(String name, String location, LocalDate date, Duration duration,
                int distance, int elevationGain)
    {
        //Call the super constructor to initialize the variables common to all the subclasses
        super(name, location, date, duration);

        //initialize the variables special to this an instance of this class
        this.distance = distance;
        this.elevation = elevationGain;

        //Track and print out details of the activity if it doesn't already exist
        if (!walkingList.searchForActivity(this))
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
     *          all Walking activities
     *
     * INPUT PARAMETERS:
     *      newActivity: The new Activity to be tracked
     *******************************************************************************/
    @Override
    public void trackActivity(Activity newActivity)
    {
        //add the new activity to the two lists
        super.trackActivity(newActivity);
        walkingList.addActivity(newActivity);

        //Keep track of the total duration of all Walking activities to avoid repeated calculation
        totalTime = totalTime.plus(getDuration());
    }

    /******************************************************************************
     * calcPace
     *
     * PURPOSE: This method calculates the pace using the duration (in minutes)
     *          and the distance (in kilometers) of the object by (duration/distance).
     *
     *  OUTPUT PARAMETERS:
     *          The method returns the calculated pace (in min/km)
     *******************************************************************************/
    private float calcPace()
    {
        return getDuration().toMinutes() / (float) distance;
    }

    /*******************************************************************************
     * print
     *
     * PURPOSE: This method prints out the details of all activities of type 'Walking'
     *          stored in the List
     *******************************************************************************/
    public static void print()
    {
        //Print out the banner and the total time across all Walking activities
        System.out.println("\n>>> Querying activities of type WALKING");
        System.out.println(">>> " + totalTime.toHoursPart() + " hour(s) and " +
                totalTime.toMinutesPart() + " minute(s).");
        System.out.println("========== Activities ==========");

        //Print out the details of each Walking activity from the Walking list
        walkingList.print();
    }

    /******************************************************************************
     * query
     *
     * PURPOSE: This method is a works in tandem with the print method and is used
     *          to print out the details of a single walking activity
     *******************************************************************************/
    public void query()
    {
        //Convert the pace (in minutes/km) to min:secs min/km format
        float pace = calcPace();
        int paceHours = ((int) pace); // get the whole number part of the minutes from the pace
        int paceMinutes = (int) ((calcPace() * 60) % 60); //convert the decimal part of the pace to seconds

        //Print out the details of the Walking activity
        System.out.println("[" + getDate() + "] Walking: " + getName() + " at " + getLocation());
        System.out.println("duration: " + this.getDuration().toHoursPart() + " hour(s) and " +
                getDuration().toMinutesPart() + " minutes(s);");
        System.out.println("distance: " + distance + "km;");
        System.out.println("elev: " + elevation + "m;");
        System.out.format("average pace: %d:%02d min/km\n\n",
                paceHours, paceMinutes);
    }

    /******************************************************************************
     * compareTo
     *
     * PURPOSE: This method is used to check if two Walking activities are the same by
     *          checking if all the fields of both activities are the same
     *
     *  OUTPUT PARAMETERS:
     *          The method returns true if the two activities are the same and false
     *          otherwise
     *******************************************************************************/
    public boolean compareTo(Activity thisActivity)
    {
        if (thisActivity instanceof Walk)
        {
            return (super.compareTo(thisActivity) && distance == ((Walk) thisActivity).distance &&
                    elevation == ((Walk) thisActivity).elevation);
        }
        return false;
    }
}
