#include <iostream>
using namespace std;

// Delete all instances of a given node

class Node
{
    int data;
    Node *next;
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
        temp->cnext(newnode);
        temp = temp->gnext();
    }
}

void del(int search)
{
    Node *temp = head;

    while (temp->gdata() == search)
    {
        head = temp->gnext();
        delete temp;
        temp = head;
    }

    while (temp->gnext() != NULL)
    {

        if (temp->gnext()->gdata() == search)
        {
            if (temp->gnext()->gnext() == NULL)
            {
                delete temp->gnext();
                temp->cnext(NULL);
                break;
            }
            else
            {
                Node *newtemp = temp->gnext();
                temp->cnext(temp->gnext()->gnext());
                delete newtemp;
                continue;
            }
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

    cout << "\n Enter the data to delete: ";
    cin >> search;
    del(search);

    cout << "\nAfter...\n";
    travese();
}
