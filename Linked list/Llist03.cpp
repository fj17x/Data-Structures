#include <iostream>
using namespace std;

//Search for a specific data in a node and insert another node before it.

class Node
{
    int data;
    Node *next;

public:
    void enter(Node *x = NULL)
    {
        cout << "\n Enter data of node: ";
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

    Node *temp = head;

    for (int i = 0; i < n - 1; i++)
    {
        Node *newnode = new Node;
        newnode->enter();
        temp->cnext(newnode);
        temp = temp->gnext();
    }
}

void insert(int search)
{

    Node *temp = head;
    Node *newtemp = new Node;

    newtemp->enter();

    if (temp->gdata() == search)
    {
        newtemp->cnext(temp);
        head = newtemp;
    }
    else
        while (temp != NULL)
        {
            if (temp->gnext()->gdata() == search)
            {
                newtemp->cnext(temp->gnext());
                temp->cnext(newtemp);
                break;
            }
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
    int n, search;
    cout << "Enter number of nodes to create: ";
    cin >> n;
    createNode(n);

    cout << "\nBefore...\n";
    travese();

    cout << "\n Enter data to search for: ";
    cin >> search;
    insert(search);

    cout << "\nAfter...\n";
    travese();
}
