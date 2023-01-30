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

    private float calcDistance()
    {
        return (lapLength * 1000) * numLaps;
    }

    private float calcPace()
    {
        return getDuration().toMinutes() / calcDistance();
    }


    public static void print()
    {
        System.out.println("\n>>> Querying activities of type SWIMMING");
        System.out.println(">>> " + totalTime.toHoursPart() + " hour(s) and " +
                totalTime.toMinutesPart() + " minute(s).");
        System.out.println("========== Activities ==========");

        //Print the details of the activity being added
        swimmingList.print();
    }

    @Override
    public void query()
    {
        float pace = calcPace();

        System.out.println("[" + getDate() + "] Swimming: " + getName() + " at " + getLocation());
        System.out.println("duration: " + this.getDuration().toHoursPart() + " hour(s) and " +
                getDuration().toMinutesPart() + " minutes(s);");
        System.out.println("number of laps: " + numLaps + " laps;");
        System.out.println("lapLength: " + lapLength + "m");
        System.out.println("average pace: " + ((int) pace) + ":" + (int) ((calcPace() * 60) % 60) + " min/km\n");
        System.out.format("average pace: %d:%02d min/km\n",
                ((int) pace), (int) ((calcPace() * 60) % 60));
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
