

#include <iostream>
using namespace std;
#define MAX 100

class Node
{
    int data;
    Node *next;

public:
    int gdata()
    {
        return data;
    }

    void cdata(int a)
    {
        data = a;
    }

    Node *gnext()
    {
        return next;
    }

    void cnext(Node *a)
    {
        next = a;
    }
} * top;

class Stack
{
    int count = 0;

public:
    void push()
    {
        int data;
        cout << "Enter the data to push: ";
        cin >> data;

        Node *temp = new Node;

        if (count == 0)
        {
            temp->cdata(data);
            temp->cnext(NULL);
            top = temp;
            count++;
        }
        else if (count == MAX)
        {
            cout << "The maximum limit has been reached.\n";
        }
        else
        {
            temp->cdata(data);
            temp->cnext(top);
            top = temp;
            count++;
        }
    }

    void pop()
    {
        if (count == 0)
        {
            cout << "Cannot pop anymore.\n";
        }
        else
        {
            Node *temp = top;
            top = top->gnext();
            cout << "This element was deleted: " << temp->gdata() << "\n";
            delete temp;
            count--;
        }
    }

    void peep()
    {
        cout << "The element at the top of the stack is: " << top->gdata() << endl;
    }

    void display()
    {
        if (count == 0)
        {
            cout << "No elements in here.\n";
            return;
        }
        Node *temp = top;
        cout << "Now displaying: ";
        while (temp != NULL)
        {
            cout << temp->gdata() << " ";
            temp = temp->gnext();
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    while (1)
    {
        int choice;
        cout << "\nEnter choice, 1-Enter, 2-Display, 3-Pop, 4-Peep, 5-Exit: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.display();
            break;
        case 3:
            s.pop();
            break;
        case 4:
            s.peep();
            break;
        case 5:
            return 0;
        }
    }
}