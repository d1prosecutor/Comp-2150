package Assignments.Assignment1;

/***********************************************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 1
 *
 * REMARKS: Implements the linked list class used to store activities.
 **********************************************************************/

import java.time.Duration;
import java.time.LocalDate;

public class ActivityList
{
    private Node top;

    //Constructor
    public ActivityList()
    {
        top = null;
    }

    //Instance Methods

    /******************************************************************************
     * addActivity
     *
     * PURPOSE: This Method adds the activity given to the list of activities
     *
     * INPUT PARAMETERS:
     *      newActivity: The new Activity to be added to the list
     *******************************************************************************/
    public void addActivity(Activity newActivity)
    {
        Node current = top;
        Node previous = null;
        if (!searchForActivity(newActivity))
        {
            //Ordered insert based on the Local date (the earliest first)
            //This loop finds the correct location to insert the new activity
            while (current != null && newActivity.getDate().isAfter(current.getData().getDate()))
            {
                previous = current;
                current = current.getNext();
            }

            //Insert the activity at the right spot
            if (previous == null)
            {
                top = new Node(newActivity, top);
            } else
            {
                Node tempNode = new Node(newActivity, previous.getNext());
                previous.setNext(tempNode);
            }
        }
    }

    /******************************************************************************
     * search
     *
     * PURPOSE: This Method uses the search method implemented in the Node class
     *          to check if an activity is already in the list
     *
     * INPUT PARAMETERS:
     *      thisActivity: The new Activity to be searched for in the list
     *
     *  OUTPUT PARAMETERS:
     *          The method returns true if the two activities are the same and false
     *          otherwise
     *******************************************************************************/
    public boolean searchForActivity(Activity thisActivity)
    {
        boolean found = false;

        if (top != null)
        {
            found = top.search(thisActivity);
        }

        return found;
    }


    /******************************************************************************
     * printBetweenDates
     *
     * PURPOSE: This Method prints all activities occurring between two specified
     *          dates
     *
     * INPUT PARAMETERS:
     *      The two parameters are the dates that specify the range of activities
     *******************************************************************************/
    public void printBetweenDates(LocalDate firstDate, LocalDate lastDate)
    {
        Duration totalTime = calcTimeBetweenDates(firstDate, lastDate);
        Node tempNode = top;

        //sum  the duration (total time) of all activities between two dates (inclusive)
        System.out.println(">>> " + totalTime.toHoursPart() + " hours and " +
                totalTime.toMinutesPart() + " minutes.");
        System.out.println("========== Activities ==========");

        //Print all the activities between these two dates (inclusive)
        while (tempNode != null)
        {
            if (tempNode.getData().getDate().isEqual(firstDate) ||
                    tempNode.getData().getDate().isEqual(lastDate) ||
                    (tempNode.getData().getDate().isAfter(firstDate) &&
                            tempNode.getData().getDate().isBefore(lastDate)) ||
                    (tempNode.getData().getDate().isAfter(lastDate) &&
                            tempNode.getData().getDate().isBefore(firstDate)))
            {
                tempNode.printSpecific();
            }
            tempNode = tempNode.getNext();
        }
    }

    /******************************************************************************
     * queryBetweenDates
     *
     * PURPOSE: This Method calculates the total duration of activities occurring
     * between two specified dates
     *
     * INPUT PARAMETERS:
     *      The two parameters are the dates that specify the range of activities
     *
     * OUTPUT PARAMETERS:
     *      The total duration of activities occurring between two specified dates
     *******************************************************************************/
    private Duration calcTimeBetweenDates(LocalDate firstDate, LocalDate lastDate)
    {
        Duration totalTime = Duration.ZERO;
        Node tempNode = top;

        while (tempNode != null)
        {
            if (tempNode.getData().getDate().isEqual(firstDate) ||
                    tempNode.getData().getDate().isEqual(lastDate) ||
                    (tempNode.getData().getDate().isAfter(firstDate) &&
                            tempNode.getData().getDate().isBefore(lastDate)) ||
                    (tempNode.getData().getDate().isAfter(lastDate) &&
                            tempNode.getData().getDate().isBefore(firstDate)))
            {
                totalTime = totalTime.plus(tempNode.getData().getDuration());
            }
            tempNode = tempNode.getNext();
        }

        return totalTime;
    }

    /**********************************************************************
     * print
     *
     * PURPOSE: This method prints out the details of all activities stored
     *          in the List
     *********************************************************************/
    public void print()
    {
        if (top != null)
        {
            top.printAll();
        }
    }
}
