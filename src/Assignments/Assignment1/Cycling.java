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

        //Keep track of the total duration of all cycling activities to avoid repeated calculation
        totalTime += duration.toHours();

        trackActivity(this);
    }


    //Update the List of all cycling activities
    //Update the List of all Activities
    @Override
    public void trackActivity(Activity newActivity)
    {
        super.trackActivity(newActivity);
        cyclingList.addActivity(newActivity);
    }

    private double calcAverageSpeed()
    {
        return (double) distance / duration.toHours();
    }

    @Override
    public void print()
    {

    }
}
