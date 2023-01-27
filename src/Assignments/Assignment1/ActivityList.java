package Assignments.Assignment1;

import java.time.Duration;
import java.time.LocalDate;

public class ActivityList
{
    private Node top;

    public ActivityList()
    {
        top = null;
    }

    public void addActivity(Activity newActivity)
    {
        Node current = top;
        Node previous = null;
        if (!searchForActivity(newActivity))
        {
            //Ordered insert based on the Local date
            while (current != null && newActivity.getDate().isAfter(current.getData().getDate()))
            {
                previous = current;
                current = current.getNext();
            }

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


    public boolean searchForActivity(Activity thisActivity)
    {
        boolean found = false;

        if (top != null)
        {
            found = top.search(thisActivity);
        }

        return found;
    }


    public void printBetweenDates(LocalDate firstDate, LocalDate lastDate)
    {
        Duration totalTime = calcTimeBetweenDates(firstDate, lastDate);
        Node tempNode = top;

        //sum  the duration (total time) of all activities between two dates (inclusive)
        System.out.println(">>> " + totalTime.toHoursPart() + " hours and " +
                totalTime.toMinutesPart() + " minutes.");
        System.out.println("========== Activities ==========");

        //Print all the activites between these two dates (inclusive)
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

    public boolean isEmpty()
    {
        return top == null;
    }


    public void print()
    {
        if (top != null)
        {
            top.printAll();
        }
    }
}
