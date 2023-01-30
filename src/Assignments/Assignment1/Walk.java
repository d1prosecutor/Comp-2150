package Assignments.Assignment1;

import java.time.Duration;
import java.time.LocalDate;

public class Walk extends Activity
{
    private int distance;
    private int elevation;
    private static Duration totalTime = Duration.ZERO;

    private static ActivityList walkingList = new ActivityList();

    public Walk(String name, String location, LocalDate date, Duration duration,
                int distance, int elevationGain)
    {
        super(name, location, date, duration);

        this.distance = distance;
        this.elevation = elevationGain;

        //Create the activity if it doesn't already exist
        if (!walkingList.searchForActivity(this))
        {
            System.out.print("Adding Activity: ");

            //Print the details of the activity being added
            query();

            trackActivity(this);
        }
    }

    //Update the List of all walking activities
    //Update the List of all Activities
    @Override
    public void trackActivity(Activity newActivity)
    {
        super.trackActivity(newActivity);
        walkingList.addActivity(newActivity);

        //Keep track of the total duration of all cycling activities to avoid repeated calculation
        totalTime = totalTime.plus(getDuration());
    }

    private float calcPace()
    {
        return getDuration().toMinutes() / (float) distance;
    }


    public static void print()
    {
        System.out.println("\n>>> Querying activities of type WALKING");
        System.out.println(">>> " + totalTime.toHoursPart() + " hour(s) and " +
                totalTime.toMinutesPart() + " minute(s).");
        System.out.println("========== Activities ==========");

        walkingList.print();
    }

    public void query()
    {
        float pace = calcPace();
        int paceHours = ((int) pace);
        int paceMinutes = (int) ((calcPace() * 60) % 60);

        System.out.println("[" + getDate() + "] Walking: " + getName() + " at " + getLocation());
        System.out.println("duration: " + this.getDuration().toHoursPart() + " hour(s) and " +
                getDuration().toMinutesPart() + " minutes(s);");
        System.out.println("distance: " + distance + "km;");
        System.out.println("elev: " + elevation + "m;");
        System.out.format("average pace: %d:%02d min/km\n\n",
                paceHours, paceMinutes);
    }

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
