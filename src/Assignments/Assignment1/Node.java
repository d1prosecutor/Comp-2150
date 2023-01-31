package Assignments.Assignment1;


public class Node
{
    //Instance variables
    private Activity data;
    private Node next;

    //Constructors
    public Node()
    {
    }

    public Node(Activity data, Node next)
    {
        this.data = data;
        this.next = next;
    }

    public boolean search(Activity thisActivity)
    {
        Node tempNode = this;
        boolean found;

        do
        {
            found = tempNode.data.compareTo(thisActivity);
            tempNode = tempNode.next;
        } while (tempNode != null && !found);

        return found;
    }

    public void printAll()
    {
        data.query();

        if (next != null)
        {
            next.printAll();
        }
    }

    public void printSpecific()
    {
        data.query();
    }

    public Node getNext()
    {
        return next;
    }

    public Activity getData()
    {
        return data;
    }

    public void setNext(Node tempNode)
    {
        next = tempNode;
    }
}
