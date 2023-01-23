package Assignments.Assignment1;

import java.io.File;
import java.io.FileNotFoundException;
import java.time.Duration;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Scanner;

public class ActivityTracker
{
    public static void main(String[] args)
    {
        //Variables for activity types
        ArrayList<String> activityTypes = new ArrayList<>();
        activityTypes.add("WALKING");
        activityTypes.add("RUNNING");
        activityTypes.add("CYCLING");
        activityTypes.add("SWIMMING");

        Scanner inputReader = new Scanner(System.in);

        System.out.println("Welcome to the COMP 2150 Activity Tracker.");
        System.out.println("Please enter the name of the file with your activities: ");

        String activityFileName = inputReader.nextLine();

        System.out.println("Going to read [" + activityFileName + "].");

        try
        {
            Scanner fileReader = new Scanner(new File(activityFileName));
            String nextLine;
            String[] tokens;

            while (fileReader.hasNextLine())
            {
                nextLine = fileReader.nextLine();
                tokens = nextLine.trim().split("\\s+");

                if (activityTypes.contains(tokens[0]))
                {
                    Activity newActivity;

                    String name = tokens[1];
                    String location = tokens[2];
                    LocalDate date = LocalDate.parse(tokens[3]);
                    Duration duration = Duration.parse(tokens[4]);

                    if (tokens[0].equals(activityTypes.get(0)))
                    {
                        int distance = Integer.parseInt(tokens[5]);
                        int elevation = Integer.parseInt(tokens[6]);

                        newActivity = new Walk(name, location, date, duration,
                                distance, elevation);
                    } else if (tokens[0].equals(activityTypes.get(1)))
                    {
                        int distance = Integer.parseInt(tokens[5]);
                        int elevation = Integer.parseInt(tokens[6]);

                        newActivity = new Walk(name, location, date, duration,
                                distance, elevation);
                    } else if (tokens[0].equals(activityTypes.get(2)))
                    {
                        int distance = Integer.parseInt(tokens[5]);
                        int elevation = Integer.parseInt(tokens[6]);

                        newActivity = new Walk(name, location, date, duration,
                                distance, elevation);
                    } else if (tokens[0].equals(activityTypes.get(3)))
                    {
                        int numlaps = Integer.parseInt(tokens[5]);
                        int lapLength = Integer.parseInt(tokens[6]);

                        newActivity = new Walk(name, location, date, duration,
                                numlaps, lapLength);
                    }
                } else if (Objects.equals(tokens[0], "QUERY"))
                {
                    if (tokens[1].equals("TOTAL_TIME"))
                    {
                    } else if (tokens[1].equals("ACTIVITY"))
                    {

                    } else if (tokens[1].equals("BETWEEN"))
                    {

                    }
                } else if (Objects.equals(tokens[0], "QUIT"))
                {
                    System.out.println("Exiting Activity Tracker...\nBye.");
                    System.exit(0);
                }
            }
        } catch (
                FileNotFoundException e)

        {
            System.out.println(e.getMessage());
        }
    }
}
