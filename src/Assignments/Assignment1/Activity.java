package Assignments.Assignment1;

import java.time.Duration;
import java.time.LocalDate;

public abstract class Activity
{
    public static ActivityList allLists;
    private static int TOTAL_TIME_SPENT_IN_ALL = 0;


    //Instance variables (Fields)
    private String name;
    private String location;

    private LocalDate date;
    private Duration duration;

    private int distance;

    private int numLaps;

    private int lapLength;

    private int elevationGain;


    public int totalTime;


    //Constrcutor
    public Activity(String name, String location, LocalDate date,
                    Duration duration, int distance, int numLaps, int lapLength, int elevationGain)
    {
        this.name = name;
        this.location = location;
        this.date = date;
        this.duration = duration;
        this.distance = distance;
        this.numLaps = numLaps;
        this.elevationGain = elevationGain;

        allLists.addActivity(this);
    }

    //Instance Methods
    private int calcPace()
    {
        //This method may not be needed
        // Convert distance to kilometers
        return 0;
    }

    private int trackDuration()
    {
        //TOTAL_TIME_SPENT_IN_ALL += duration;
        //In child classes, track total duration of specific activities
        return 0;
    }

    private boolean searchForActivity()
    {
        return false;
    }

    public abstract void print();

    public LocalDate getDate()
    {
        return date;
    }
}
