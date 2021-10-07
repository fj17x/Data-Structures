#include <iostream>
using namespace std;

//Search for a specific data in a node and insert another node before/after it.

class Node
{
    int data;
    Node *next, *prev;

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

void insert(int search, int choice)
{
    cout << "\n Enter data to search for: ";
    cin >> search;

    Node *temp = head, *temp2;
    Node *newtemp = new Node;

    newtemp->enter();

    if (choice == 1)
    {
        // enter before

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
    else if (choice == 2)
    {
        // enter after

        while (temp != NULL)
        {
            if (temp->gdata() == search)
            {
                newtemp->cnext(temp->gnext());
                temp->cnext(newtemp);
                break;
            }
            temp = temp->gnext();
        }
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

int main()
{
    int n, search, choice;
    cout << "Enter number of nodes to create: ";
    cin >> n;
    createNode(n);

    cout << "\nPlease enter one of the following numbers:-\n\t1- If you want to enter before \n\t2- If you want to enter after\n";
    cin >> choice;

    insert(search, choice);

    cout << "\nAfter...\n";
    travese();
}
