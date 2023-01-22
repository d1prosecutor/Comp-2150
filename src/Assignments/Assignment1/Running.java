package Assignments.Assignment1;

import java.time.Duration;
import java.time.LocalDate;

public class Running extends Activity
{


    public Running(String name, String location, LocalDate date, Duration duration,
                   int distance, int numLaps, int lapLength, int elevationGain)
    {
        super(name, location, date, duration, distance, numLaps, lapLength, elevationGain);

        // totalTime+=duration;

    }

    @Override
    public void print()
    {

    }

    private long calcPace(int distance, Duration duration)
    {
        return duration.toMinutes() / distance;
    }

    private int trackDuration()
    {
        return 0;
    }
}
