package Assignments.Assignment1;

import java.time.Duration;
import java.time.LocalDate;
//import java.time.LocalTime;

public class Cycle extends Activity
{
    private int distance;
    private int elevation;

    private static ActivityList cyclingList = new ActivityList();
    private static Duration totalTime = Duration.ZERO;

    public Cycle(String name, String location, LocalDate date, Duration duration,
                 int distance, int elevationGain)
    {
        super(name, location, date, duration);

        this.distance = distance;
        this.elevation = elevationGain;

        //Create the activity if it doesn't already exist
        if (!cyclingList.searchForActivity(this))
        {
            System.out.print("Adding Activity: ");

            //Print the details of the activity being added
            query();

            trackActivity(this);
        }
    }


    //Update the List of all cycling activities
    //Update the List of all Activities
    @Override
    public void trackActivity(Activity newActivity)
    {
        super.trackActivity(newActivity);
        cyclingList.addActivity(newActivity);

        //Keep track of the total duration of all cycling activities to avoid repeated calculation
        totalTime = totalTime.plus(getDuration());
    }

    private float calcSpeed()
    {
        return (float) distance * 60 / getDuration().toMinutes();
    }


    public static void print()
    {
        System.out.println(">>> Querying activities of type CYCLING");
        System.out.println("========== Activities ==========");

        cyclingList.print();
    }

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

    public boolean compareTo(Activity thisActivity)
    {
        return (super.compareTo(thisActivity) && (distance == ((Cycle) thisActivity).distance) &&
                (elevation == ((Cycle) thisActivity).elevation));
    }
}
