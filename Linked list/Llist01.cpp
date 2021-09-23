#include <iostream>
using namespace std;

// Create 5 nodes and access them using the first node.

class Node
{
    int data;
    Node *next;

public:
    void enter(Node *x = NULL)
    {
        cout << "\n Enter data: ";
        cin >> data;
        next = x;
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

int main()
{
    n1.enter(&n2);
    n2.enter(&n3);
    n3.enter(&n4);
    n4.enter(&n5);
    n5.enter();

    cout << "\n 1st Node: " << n1.gdata();
    cout << "\n Accessing 2nd node using first: " << n1.gnext()->gdata();
    cout << "\n Accessing 3nd node using first: " << n1.gnext()->gnext()->gdata();
    cout << "\n Accessing 4th node using first: " << n1.gnext()->gnext()->gnext()->gdata();
    cout << "\n Accessing 5th node using first: " << n1.gnext()->gnext()->gnext()->gnext()->gdata();
}
