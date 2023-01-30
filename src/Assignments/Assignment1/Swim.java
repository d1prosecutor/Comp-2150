package Assignments.Assignment1;

import java.time.Duration;
import java.time.LocalDate;

public class Swim extends Activity
{
    private int numLaps;
    private int lapLength;
    private static Duration totalTime = Duration.ZERO;

    private static ActivityList swimmingList = new ActivityList();

    public Swim(String name, String location, LocalDate date,
                Duration duration, int numLaps, int lapLength)
    {
        super(name, location, date, duration);

        this.numLaps = numLaps;
        this.lapLength = lapLength;

        //Create the activity if it doesn't already exist
        if (!swimmingList.searchForActivity(this))
        {
            System.out.print("Adding Activity: ");

            //Print the details of the activity being added
            query();

            trackActivity(this);
        }
    }

    //Update the List of all swimming activities
    //Update the List of all Activities
    @Override
    public void trackActivity(Activity newActivity)
    {
        super.trackActivity(newActivity);
        swimmingList.addActivity(newActivity);

        //Keep track of the total duration of all cycling activities to avoid repeated calculation
        totalTime = totalTime.plus(getDuration());
    }

    private double calcDistance()
    {
        return (lapLength * 1000) * numLaps;
    }

    private double calcPace()
    {
        return getDuration().toMinutes() / calcDistance();
    }


    public static void print()
    {
        System.out.println(">>> Querying activities of type SWIMMING");
        System.out.println("========== Activities ==========");

        //Print the details of the activity being added
        swimmingList.print();
    }

    @Override
    public void query()
    {
        System.out.println("[" + getDate() + "] Swimming: " + getName() + " at " + getLocation());
        System.out.println("duration: " + this.getDuration().toHoursPart() + " hour(s) and " +
                getDuration().toMinutesPart() + " minutes(s);");
        System.out.println("number of laps: " + numLaps + " laps;");
        System.out.println("lapLength: " + lapLength + "m");
        System.out.format("average pace: %.2fmin/km;\n\n", calcPace());
    }

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
