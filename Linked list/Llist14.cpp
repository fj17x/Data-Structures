#include <iostream>
using namespace std;

//Create a linked list that stores details about students.

class Node
{
    char name[20];
    int age;
    float marks;
    Node *next;

public:
    void enter(Node *x = NULL)
    {
        cout << "\n Enter name of the student: ";
        cin >> name;

        cout << " Enter age of the student: ";
        cin >> age;

        cout << " Enter marks of the student: ";
        cin >> marks;

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

    void display()
    {
        cout << "\n Student Name: " << name;
        cout << "\n Student Age: " << age;
        cout << "\n Student Marks: " << marks;
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
        cout << endl;
        temp->display();
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
