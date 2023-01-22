package Assignments.Assignment1;

import java.time.Duration;
import java.time.LocalDate;

public class Swimming extends Activity
{


    public Swimming(String name, String location, LocalDate date, Duration duration,
                    int distance, int numLaps, int lapLength, int elevationGain)
    {
        super(name, location, date, duration, distance, numLaps, lapLength, elevationGain);
        // totalTime+=duration;
    }

    @Override
    public void print()
    {

    }

    private int calcPace(int distance, int duration)
    {
        return duration / distance;
    }

    private int trackDuration()
    {
        return 0;
    }
}
