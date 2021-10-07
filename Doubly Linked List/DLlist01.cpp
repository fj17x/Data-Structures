#include <iostream>
using namespace std;

//Create n number of nodes and traverse through them.

class Node
{
    int data;
    Node *next, *prev;
    static int count;

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

int Node::count = 1;

void createNode(int n)
{
    head = new Node;
    head->enter();

    Node *temp = head;

    for (int i = 0; i < n - 1; i++)
    {
        Node *newnode = new Node;
        newnode->enter();
        newnode->cprev(temp);
        temp->cnext(newnode);
        temp = temp->gnext();
    }
}

void travese()
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << "\n " << temp->gdata() << endl;
        temp = temp->gnext();
    }
}

int main()
{
    int n;
    cout << "Enter number of nodes to create: ";
    cin >> n;
    createNode(n);

    cout << "\nNow traversing through the data of the nodes...\n";
    travese();
}
