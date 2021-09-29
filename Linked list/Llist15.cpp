#include <iostream>
using namespace std;

// Create a circular linked list in which we can delete and insert an element.

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

} * head, *tail;

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
    temp->cnext(head);
    tail = temp;
}

void del(int search)
{
    Node *temp = head;

    if (temp->gdata() == search)
    {
        head = temp->gnext();
        delete temp;
        temp = head;
        tail->cnext(temp);
        return;
    }

    do
    {
        if (temp->gnext()->gdata() == search)
        {
            Node *newtemp = temp->gnext();
            temp->cnext(temp->gnext()->gnext());
            delete newtemp;

            if (temp->gnext() == head)
            {
                tail = temp;
            }
            return;
        }
        temp = temp->gnext();
    } while (temp != head);
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
        tail->cnext(head);
    }
    else
        do
        {
            if (temp->gnext()->gdata() == search)
            {
                newtemp->cnext(temp->gnext());
                temp->cnext(newtemp);
                break;
            }
            temp = temp->gnext();
        } while (temp != head);
}

void travese()
{
    Node *temp = head;
    do
    {
        cout << "\n " << temp->gdata() << endl;
        temp = temp->gnext();
    } while (temp != head);
}

int main()
{
    int n, ele, k;
    cout << "Enter number of nodes to create: ";
    cin >> n;
    createNode(n);

    cout << "\nEnter 1 to insert and 2 to delete an element: ";
    cin >> k;
    switch (k)
    {

    case 1:
        cout << "\n Which element do you want to insert before?: ";
        cin >> ele;
        insert(ele);
        break;

    case 2:
        cout << "\n Enter what element to delete: ";
        cin >> ele;
        del(ele);
    }

    cout << "\nNow traversing through the data of the nodes...\n";
    travese();
}
