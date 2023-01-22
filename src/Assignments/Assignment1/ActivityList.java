package Assignments.Assignment1;

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
            top.search(thisActivity);
        }

        return found;
    }


    public int calculateTimeBetweenDates(LocalDate firstDate, LocalDate lastDate)
    {
        int totalTime = 0;
        Node tempNode = top;

        //sum  the duration (total time) of all activities between two dates (inclusive)
        while (tempNode != null)
        {
            if (tempNode.getData().getDate().isEqual(firstDate) ||
                    tempNode.getData().getDate().isEqual(lastDate) ||
                    (tempNode.getData().getDate().isAfter(firstDate) &&
                            tempNode.getData().getDate().isBefore(lastDate)))
            {
                totalTime += tempNode.getData().getDuration().toHours();
                tempNode = tempNode.getNext();
            }
        }

        return totalTime;
    }
}
