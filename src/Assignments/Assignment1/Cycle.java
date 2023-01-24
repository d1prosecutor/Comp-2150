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

        //Print the details of the activity being added
        query();

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
        totalTime = totalTime.plus(duration);
    }

    private float calcSpeed()
    {
        return (float) distance * 60 / duration.toMinutes();
    }


    public void print()
    {
        System.out.println(">>> Querying activities of type CYCLING");
        System.out.println("========== Activities ==========");
    }

    @Override
    public void query()
    {
        super.query();
        System.out.println("duration: " + this.getDuration().toHoursPart() + " hour(s) and " +
                getDuration().toMinutesPart() + " minutes(s);");
        System.out.println("distance: " + distance + "km;");
        System.out.println("elev: " + elevation + "m;");
        System.out.format("average speed: %.2fkm/h;\n\n", calcSpeed());
    }
}
