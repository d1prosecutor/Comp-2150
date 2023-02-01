package Assignments.Assignment1;

/***************************************************************************************
 * NAME: Chukwunaza Chukwuocha
 * STUDENT NUMBER: 7928676
 * COURSE: COMP 2150, SECTION: A02
 * INSTRUCTOR: Olivier Tremblay-Savard
 * ASSIGNMENT: Assignment 1
 *
 * REMARKS: Implements the Node class used for the linked list to store activities.
 ***************************************************************************************/

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

    //Instance Methods

    /******************************************************************************
     * search
     *
     * PURPOSE: This Method uses the compareTo method implemented in the Subclasses
     *          of Activity to check if two activities are the same(have same fields)
     *
     * INPUT PARAMETERS:
     *      thisActivity: The new Activity to be searched for in the list
     *
     *  OUTPUT PARAMETERS:
     *          The method returns true if the two activities are the same and false
     *          otherwise
     *******************************************************************************/
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

    /******************************************************************************
     * printAll
     *
     * PURPOSE: This Method recursively prints the details of all nodes in the list
     *          using the query method implemented in the subclasses of Activity
     *******************************************************************************/
    public void printAll()
    {
        data.query();

        if (next != null)
        {
            next.printAll();
        }
    }

    /******************************************************************************
     * printSpecific
     *
     * PURPOSE: This Method recursively prints the details of a single node in the
     *          list using the query method implemented in the subclasses of Activity
     *******************************************************************************/
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
