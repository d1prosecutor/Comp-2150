package Assignments.Assignment1;
/*******************************************************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 1
 *
 * REMARKS: Implements the Cycle class, which is a type of Activity(superclass).
 ******************************************************************************/

import java.time.Duration;
import java.time.LocalDate;

public class Cycle extends Activity
{
    //Static variables
    private static Duration totalTime = Duration.ZERO;

    private static ActivityList cyclingList = new ActivityList();

    //Instance variables
    private int distance;
    private int elevation;

    //Constructors
    public Cycle()
    {
    }

    public Cycle(String name, String location, LocalDate date, Duration duration,
                 int distance, int elevationGain)
    {
        //Call the super constructor to initialize the variables common to all the subclasses
        super(name, location, date, duration);

        //initialize the variables special to this an instance of this class
        this.distance = distance;
        this.elevation = elevationGain;

        //Track and print out details of the activity if it doesn't already exist
        if (!cyclingList.searchForActivity(this))
        {
            System.out.print("Adding Activity: ");

            //Print the details of the activity being added
            query();

            trackActivity(this);
        }
    }

    //Instance Methods

    /******************************************************************************
     * trackActivity
     *
     * PURPOSE: This Method adds the particular object(instance) being worked on to
     *          the list of all activities (using the super method) and the list containing
     *          all Cycling activities
     *
     * INPUT PARAMETERS:
     *      newActivity: The new Activity to be tracked
     *******************************************************************************/
    @Override
    public void trackActivity(Activity newActivity)
    {
        //add the new activity to the two lists
        super.trackActivity(newActivity);
        cyclingList.addActivity(newActivity);

        //Keep track of the total duration of all Cycling activities to avoid repeated calculation
        totalTime = totalTime.plus(getDuration());
    }

    /******************************************************************************
     * calcPace
     *
     * PURPOSE: This method calculates the speed using the duration (to hours)
     *          and the distance (in kilometers) of the object by (distance/duration).
     *
     *  OUTPUT PARAMETERS:
     *          The method returns the calculated speed (in km/hr)
     *******************************************************************************/
    private float calcSpeed()
    {
        return (float) distance * 60 / getDuration().toMinutes();
    }


    /*******************************************************************************
     * print
     *
     * PURPOSE: This method prints out the details of all activities of type 'Cycling'
     *          stored in the List
     *******************************************************************************/
    public static void print()
    {
        //Print out the banner and the total time across all Cycling activities
        System.out.println("\n>>> Querying activities of type CYCLING");
        System.out.println(">>> " + totalTime.toHoursPart() + " hour(s) and " +
                totalTime.toMinutesPart() + " minute(s).");
        System.out.println("========== Activities ==========");

        //Print out the details of each Cycling activity from the Cycling list
        cyclingList.print();
    }

    /******************************************************************************
     * query
     *
     * PURPOSE: This method is a works in tandem with the print method and is used
     *          to print out the details of a single Cycling activity
     *******************************************************************************/
    @Override
    public void query()
    {
        System.out.println("[" + getDate() + "] Cycling: " + getName() + " at " + getLocation());
        System.out.println("duration: " + this.getDuration().toHoursPart() + " hour(s) and " +
                getDuration().toMinutesPart() + " minutes(s);");
        System.out.println("distance: " + distance + "km;");
        System.out.println("elev: " + elevation + "m;");
        System.out.format("average speed: %.2fkm/h;\n\n", calcSpeed());
    }

    /******************************************************************************
     * compareTo
     *
     * PURPOSE: This method is used to check if two Cycling activities are the same by
     *          checking if all the fields of both activities are the same
     *
     *  OUTPUT PARAMETERS:
     *          The method returns true if the two activities are the same and false
     *          otherwise
     *******************************************************************************/
    public boolean compareTo(Activity thisActivity)
    {
        if (thisActivity instanceof Cycle)
        {
            return (super.compareTo(thisActivity) && (distance == ((Cycle) thisActivity).distance) &&
                    (elevation == ((Cycle) thisActivity).elevation));
        }
        return false;
    }
}
