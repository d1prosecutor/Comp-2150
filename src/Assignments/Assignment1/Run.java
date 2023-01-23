package Assignments.Assignment1;

import java.time.Duration;
import java.time.LocalDate;

public class Run extends Activity
{
    private int distance;
    private int elevation;
    private static int totalTime;

    private static ActivityList runningList = new ActivityList();

    public Run(String name, String location, LocalDate date, Duration duration,
               int distance, int elevationGain)
    {
        super(name, location, date, duration);
        this.distance = distance;
        this.elevation = elevationGain;

        //Print the details of the activity being added
        query();

        trackActivity(this);
    }

    //Update the List of all running activities
    //Update the List of all Activities
    @Override
    public void trackActivity(Activity newActivity)
    {
        super.trackActivity(newActivity);
        runningList.addActivity(newActivity);

        //Keep track of the total duration of all cycling activities to avoid repeated calculation
        totalTime += duration.toHours();
    }

    private double calcPace()
    {
        return duration.toMinutes() / (double) distance;
    }

    @Override
    public void print()
    {
        System.out.println(">>> Querying activities of type RUNNING");
        System.out.println("========== Activities ==========");
    }

    @Override
    public void query()
    {
        System.out.println(date + " " + "Running: " + this.name + "at " + this.location);
        System.out.println("duration: " + this.getDuration().toHoursPart() + " hour(s) and " +
                getDuration().toMinutesPart() + " minutes(s);");
        System.out.println("distance: " + distance + "km;");
        System.out.println("elev: " + elevation + "m;");
        System.out.println("average pace : " + calcPace() + "km/h;");
    }
}
