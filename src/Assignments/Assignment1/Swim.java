package Assignments.Assignment1;

import java.time.Duration;
import java.time.LocalDate;

public class Swim extends Activity
{
    private int numLaps;
    private int lapLength;
    private static int totalTime;

    private static ActivityList swimmingList = new ActivityList();

    public Swim(String name, String location, LocalDate date,
                Duration duration, int numLaps, int lapLength)
    {
        super(name, location, date, duration);
        this.numLaps = numLaps;
        this.lapLength = lapLength;

        trackActivity(this);
    }

    //Update the List of all swimming activities
    //Update the List of all Activities
    @Override
    public void trackActivity(Activity newActivity)
    {
        super.trackActivity(newActivity);
        swimmingList.addActivity(newActivity);

        //Keep track of the total duration of all cycling activities to avoid repeated calculation
        totalTime += duration.toHours();
    }

    private double calcDistance()
    {
        return (lapLength * 1000) * numLaps;
    }

    private double calcPace()
    {
        return duration.toMinutes() / calcDistance();
    }

    @Override
    public void print()
    {
        System.out.println(">>> Querying activities of type SWIMMING");
        System.out.println("========== Activities ==========");

        //Print the details of the activity being added
        query();

        swimmingList.print();
    }

    @Override
    public void query()
    {
        System.out.println(date + " " + "Running: " + this.name + "at " + this.location);
        System.out.println("duration: " + this.getDuration().toHoursPart() + " hour(s) and " +
                getDuration().toMinutesPart() + " minutes(s);");
        System.out.println("number of laps: " + numLaps + " laps;");
        System.out.println("lapLength: " + lapLength + "m");
        System.out.println("average pace : " + calcPace() + "km/h;");
    }
}
