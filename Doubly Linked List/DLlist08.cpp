#include <iostream>
using namespace std;

// Display frequency of a data numbers in nodes

class Node
{
    int data;
    Node *next, *prev;

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
    void cprev(Node *x)
    {
        prev = x;
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
        newnode->cprev(temp);
        temp->cnext(newnode);
        temp = temp->gnext();
    }
}

bool checkprime(int x)
{
    int limit = x / 2;

    if (x == 1 || x == 2 || x < 1)
    {
        return false;
    }

    for (int i = 2; i < limit; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

void freq()
{
    Node *temp = head;
    int d, count = 0;

    cout << "\n Enter data to search frequency of: ";
    cin >> d;

    while (temp != NULL)
    {
        if (temp->gdata() == d)
        {
            count++;
        }
        temp = temp->gnext();
    }

    cout << "\nThe frequency is: " << count;
}

int main()
{
    int n;
    cout << "Enter number of nodes to create: ";
    cin >> n;
    createNode(n);

    freq();
}
