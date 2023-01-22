package Assignments.Assignment1;

import java.time.Duration;
import java.time.LocalDate;
import java.time.LocalTime;

public class Cycling extends Activity
{


    public Cycling(String name, String location, LocalDate date, Duration duration,
                   int distance, int numLaps, int lapLength, int elevationGain)
    {
        super(name, location, date, duration, distance, numLaps, lapLength, elevationGain);

        // totalTime+=duration;
    }

    @Override
    public void print()
    {

    }

    private long calcAverageSpeed(int distance, Duration time)
    {
        return distance / time.toHours();
    }

    private int trackDuration()
    {
        return 0;
    }
}
