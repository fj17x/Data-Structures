#include <iostream>
using namespace std;

//Create n number of nodes and traverse through them.

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
