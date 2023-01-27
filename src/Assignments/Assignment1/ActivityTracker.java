package Assignments.Assignment1;

import java.io.File;
import java.io.FileNotFoundException;
import java.time.Duration;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Scanner;

public class ActivityTracker
{
    public static void main(String[] args)
    {
        //Variables for activity types

        String running = "RUNNING";
        String walking = "WALKING";
        String cycling = "CYCLING";
        String swimming = "SWIMMING";

        ArrayList<String> activityTypes = new ArrayList<>();
        activityTypes.add(walking);
        activityTypes.add(running);
        activityTypes.add(cycling);
        activityTypes.add(swimming);


        Scanner inputReader = new Scanner(System.in);

        System.out.println("Welcome to the COMP 2150 Activity Tracker.");
        System.out.println("Please enter the name of the file with your activities: ");

        String activityFileName = inputReader.nextLine();

        System.out.println("Going to read [" + activityFileName + "]...\n");

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

                    LocalDate date;
                    if (tokens[3].equalsIgnoreCase("today"))
                    {
                        date = LocalDate.now();
                    } else
                    {
                        date = LocalDate.parse(tokens[3]);
                    }

                    Duration duration = Duration.parse(tokens[4]);

                    if (tokens[0].equals(walking))
                    {
                        int distance = Integer.parseInt(tokens[5]);
                        int elevation = Integer.parseInt(tokens[6]);

                        newActivity = new Walk(name, location, date, duration,
                                distance, elevation);
                    } else if (tokens[0].equals(running))
                    {
                        int distance = Integer.parseInt(tokens[5]);
                        int elevation = Integer.parseInt(tokens[6]);

                        newActivity = new Run(name, location, date, duration,
                                distance, elevation);
                    } else if (tokens[0].equals(cycling))
                    {
                        int distance = Integer.parseInt(tokens[5]);
                        int elevation = Integer.parseInt(tokens[6]);

                        newActivity = new Cycle(name, location, date, duration,
                                distance, elevation);
                    } else if (tokens[0].equals(swimming))
                    {
                        int numlaps = Integer.parseInt(tokens[5]);
                        int lapLength = Integer.parseInt(tokens[6]);

                        newActivity = new Swim(name, location, date, duration,
                                numlaps, lapLength);
                    }
                } else if (tokens[0].equals("QUERY"))
                {
                    if (tokens[1].equals("TOTAL_TIME"))
                    {
                        Activity.print();
                    } else if (tokens[1].equals("ACTIVITY"))
                    {
                        String activityType = tokens[2];
                        if (activityType.equals(walking))
                        {
                            Walk.print();
                        } else if (activityType.equals(running))
                        {
                            Run.print();
                        } else if (activityType.equals(cycling))
                        {
                            Cycle.print();
                        } else if (activityType.equals(swimming))
                        {
                            Swim.print();
                        }
                    } else if (tokens[1].equals("BETWEEN"))
                    {
                        LocalDate firstDate;
                        LocalDate secondDate;


                        if (tokens[2].equalsIgnoreCase("today"))
                        {
                            firstDate = LocalDate.now();
                        } else
                        {
                            firstDate = LocalDate.parse(tokens[2]);
                        }

                        if (tokens[3].equalsIgnoreCase("today"))
                        {
                            secondDate = LocalDate.now();
                        } else
                        {
                            secondDate = LocalDate.parse(tokens[3]);
                        }

                        Activity.queryBetweenDates(firstDate, secondDate);
                    }
                } else if (tokens[0].equals("QUIT"))
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
