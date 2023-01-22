package Assignments.Assignment1;

import java.time.Duration;
import java.time.LocalDate;

public class Walking extends Activity
{
    private int distance;
    private int elevation;
    private static int totalTime;

    private static ActivityList walkingList = new ActivityList();

    public Walking(String name, String location, LocalDate date, Duration duration,
                   int distance, int elevationGain)
    {
        super(name, location, date, duration);
        this.distance = distance;
        this.elevation = elevationGain;

        //Keep track of the total duration of all cycling activities to avoid repeated calculation
        totalTime += duration.toHours();

        trackActivity(this);
    }

    //Update the List of all walking activities
    //Update the List of all Activities
    @Override
    public void trackActivity(Activity newActivity)
    {
        super.trackActivity(newActivity);
        walkingList.addActivity(newActivity);
    }

    private double calcPace()
    {
        return duration.toMinutes() / (double) distance;
    }

    private int trackDuration()
    {
        return 0;
    }

    @Override
    public void print()
    {

    }
}
