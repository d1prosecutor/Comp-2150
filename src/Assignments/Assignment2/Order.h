#include <string>
using namespace std;

class Order
{
private:
    // Class variables
    static int ID;

    // Instance Variables
    int currTime;
    string customerType;
    int orderValue;
    int arrivalTime;
    int orderID;

public:
    // Constructors
    Order();
    Order(int, string, int, int);

    // Instance Variables
    void setCurrTime(int);
    const int getOrderID();
    const int getCurrTime();
    const int getOrderValue();
    const int getArrivalTime();
    const string getCustomerType();
};