#include <iostream>
using namespace std;

// Create 5 nodes and access them using the first node.

class Node
{
    int data;
    static int count;
    Node *next;

public:
    void enter(Node *x = NULL)
    {
        cout << "Enter data of node " << count << ": ";
        cin >> data;
        next = x;
        count++;
    }

    Node *gnext()
    {
        return next;
    }

    int gdata()
    {
        return data;
    }

} n1, n2, n3, n4, n5;

int Node::count = 1;

int main()
{
    n1.enter(&n2);
    n2.enter(&n3);
    n3.enter(&n4);
    n4.enter(&n5);
    n5.enter();

    cout << "\nAccessing the 1st Node: " << n1.gdata();
    cout << "\nAccessing 2nd node using 1st: " << n1.gnext()->gdata();
    cout << "\nAccessing 3nd node using 1st: " << n1.gnext()->gnext()->gdata();
    cout << "\nAccessing 4th node using 1st: " << n1.gnext()->gnext()->gnext()->gdata();
    cout << "\nAccessing 5th node using 1st: " << n1.gnext()->gnext()->gnext()->gnext()->gdata();
}
