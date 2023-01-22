package Assignments.Assignment1;

public class ActivityList
{
    private Node top;

    public ActivityList()
    {
        top = null;
    }

    public void addActivity(Activity newActivity)
    {

    }

    public void insert(Activity newActivity)
    {
        Node current = top;
        Node previous = null;
        if (!searchForActivity(newActivity))
        {
            //Ordered insert based on the Local date
            while (current != null && newActivity.getDate().compareTo(current.getData().getDate()) > 0)
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


}
