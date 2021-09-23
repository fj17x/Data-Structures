#include <iostream>
using namespace std;

//Create n number of nodes so that it is always in sorted order.

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

void travese()
{
    Node *temp = head;

    cout << endl;
    while (temp != NULL)
    {
        cout << " " << temp->gdata() << endl;
        temp = temp->gnext();
    }
}

void createNode(int n)
{
    head = new Node;
    head->enter();

    Node *temp = head;

    for (int i = 0; i < n - 1; i++)
    {
        Node *newnode = new Node;
        newnode->enter();

        if (i == 0)
        {
            if (newnode->gdata() < head->gdata())
            {
                newnode->cnext(head);
                head = newnode;
            }
            else
                head->cnext(newnode);
            continue;
        }

        temp = head;

        if (newnode->gdata() < head->gdata())
        {
            newnode->cnext(head);
            head = newnode;
            continue;
        }

        while (temp->gnext() != NULL)
        {

            if (newnode->gdata() > temp->gdata() && newnode->gdata() < temp->gnext()->gdata())
            {
                newnode->cnext(temp->gnext());
                temp->cnext(newnode);
                break;
            }

            temp = temp->gnext();

            if (newnode->gdata() == temp->gdata())
            {
                newnode->cnext(temp->gnext());
                temp->cnext(newnode);
                break;
            }

            if (temp->gnext() == NULL && newnode->gdata() > temp->gdata())
            {
                temp->cnext(newnode);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of nodes to create: ";
    cin >> n;
    createNode(n);

    cout << "\nShowing sorted linked list...\n";
    travese();
}