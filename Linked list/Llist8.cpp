#include <iostream>
using namespace std;

// Display max and min number of the nodes

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

    void cnext(Node *x)
    {
        next = x;
    }

    int gdata()
    {
        return data;
    }

} * head;

void createNode(int n)
{
    head = new Node;
    head->enter();

    Node *temp = new Node;
    temp = head;

    for (int i = 0; i < n - 1; i++)
    {
        Node *newnode = new Node;
        newnode->enter();
        temp->cnext(newnode);
        temp = temp->gnext();
    }
}

void minmax()
{
    Node *temp = head;
    int max = head->gdata(), min = head->gdata();

    while (temp != NULL)
    {
        if (temp->gdata() > max)
            max = temp->gdata();

        if (temp->gdata() < min)
            min = temp->gdata();

        temp = temp->gnext();
    }

    cout << "\n  Max = " << max << endl;
    cout << "\n  Min = " << min << endl;
}

int main()
{
    int n;
    cout << "Enter number of nodes to create: ";
    cin >> n;
    createNode(n);

    cout << "\nNow displaying max and min data in the nodes...\n";
    minmax();
}