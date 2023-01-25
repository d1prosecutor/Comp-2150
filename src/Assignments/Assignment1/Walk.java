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

        //Print the details of the activity being added
        query();

        trackActivity(this);
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

    private double calcPace()
    {
        return getDuration().toMinutes() / (double) distance;
    }


    public static void print()
    {
        System.out.println(">>> Querying activities of type WALKING");
        System.out.println("========== Activities ==========");

        walkingList.print();
    }

    public void query()
    {
        super.query();
        System.out.println("duration: " + this.getDuration().toHoursPart() + " hour(s) and " +
                getDuration().toMinutesPart() + " minutes(s);");
        System.out.println("distance: " + distance + "km;");
        System.out.println("elev: " + elevation + "m;");
        System.out.format("average pace: %.2fmin/km;\n\n", calcPace());
    }
}
