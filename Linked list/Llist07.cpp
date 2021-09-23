#include <iostream>
using namespace std;

// Display only prime numbers in nodes

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

void ptravese()
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (checkprime(temp->gdata()))
        {
            cout << "\n " << temp->gdata() << endl;
        }
        temp = temp->gnext();
    }
}

int main()
{
    int n;
    cout << "Enter number of nodes to create: ";
    cin >> n;
    createNode(n);

    cout << "\nNow displaying prime data through the nodes...\n";
    ptravese();
}
