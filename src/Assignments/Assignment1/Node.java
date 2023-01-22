package Assignments.Assignment1;


public class Node
{
    private Activity data;
    private Node next;

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
            found = tempNode.data == thisActivity;
            tempNode = tempNode.next;
        } while (tempNode != null && !found);

        return found;
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
