#include <iostream>
using namespace std;

// Sort the data in the nodes in either ascending or descending order.

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

    void cdata(int x)
    {
        data = x;
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

void sort(int n, int choice)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (Node *j = head; j->gnext() != NULL; j = j->gnext())
        {
            if (choice == 1) // ascending sort
                if (j->gdata() > j->gnext()->gdata())
                {
                    temp = j->gnext()->gdata();
                    j->gnext()->cdata(j->gdata());
                    j->cdata(temp);
                }
            if (choice == 2) // descending sort
                if (j->gdata() < j->gnext()->gdata())
                {
                    temp = j->gnext()->gdata();
                    j->gnext()->cdata(j->gdata());
                    j->cdata(temp);
                }
        }
    }
}

int main()
{
    int n, choice;
    cout << "Enter number of nodes to create: ";
    cin >> n;
    createNode(n);

    cout << "\nPlease enter one of the following numbers:-\n\t1- If you want to sort by Ascending \n\t2- If you want to sort by Descending\n";
    cin >> choice;

    sort(n, choice);

    cout << "\nAfter...\n";
    travese();
}
