package Assignments.Assignment1;

import java.time.Duration;
import java.time.LocalDate;
//import java.time.LocalTime;

public class Cycling extends Activity
{
    private int distance;
    private int elevation;

    private static ActivityList cyclingList;
    private static int totalTime;

    public Cycling(String name, String location, LocalDate date, Duration duration,
                   int distance, int elevationGain)
    {
        super(name, location, date, duration);
        this.distance = distance;
        this.elevation = elevationGain;

        trackActivity(this);
    }


    //Update the List of all cycling activities
    //Update the List of all Activities
    @Override
    public void trackActivity(Activity newActivity)
    {
        super.trackActivity(newActivity);
        cyclingList.addActivity(newActivity);

        //Keep track of the total duration of all cycling activities to avoid repeated calculation
        totalTime += duration.toHours();
    }

    private double calcAverageSpeed()
    {
        return (double) distance / duration.toHours();
    }

    @Override
    public void print()
    {
        System.out.println("========== Activities ==========");
        System.out.println(date + " " + "Running: " + this.name + "at " + this.location);
        System.out.println("duration: " + this.getDuration().toHoursPart() + " hour(s) and " +
                getDuration().toMinutesPart() + " minutes(s);");
        System.out.println("distance: " + distance + "km;");
        System.out.println("elev: " + elevation + "m;");
        System.out.println("average pace : " + calcAverageSpeed() + "km/h;");
    }
}
