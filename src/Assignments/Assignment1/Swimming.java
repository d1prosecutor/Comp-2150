package Assignments.Assignment1;

import java.time.Duration;
import java.time.LocalDate;

public class Swimming extends Activity
{
    private int numLaps;
    private int lapLength;
    private static int totalTime;

    private static ActivityList swimmingList = new ActivityList();

    public Swimming(String name, String location, LocalDate date,
                    Duration duration, int numLaps, int lapLength)
    {
        super(name, location, date, duration);
        this.numLaps = numLaps;
        this.lapLength = lapLength;

        //Keep track of the total duration of all cycling activities to avoid repeated calculation
        totalTime += duration.toHours();

        trackActivity(this);
    }

    //Update the List of all swimming activities
    //Update the List of all Activities
    @Override
    public void trackActivity(Activity newActivity)
    {
        super.trackActivity(newActivity);
        swimmingList.addActivity(newActivity);
    }

    private double calcPace()
    {
        double distance = (lapLength / 1000.0) * numLaps;
        return duration.toMinutes() / distance;
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
