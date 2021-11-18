#include <iostream>
using namespace std;
#define MAX 100

int stack[MAX], top = -1;

void push(int data)
{
    if (top == MAX - 1)
        cout << "Exceeded limit\n";
    else
    {
        top++;
        stack[top] = data;
    }
}

void display()
{
    cout << "Now displaying: ";
    int i = top;

    while (i >= 0)
    {
        cout << stack[i] << " ";
        i--;
    }

    cout << endl;
}

void pop()
{
    if (top == -1)
        cout << "Cannot pop any longer.\n";
    else
    {
        cout << stack[top--] << " was removed.\n";
    }
}

void peep()
{
    cout << "The element at the top of the stack is: " << stack[top] << endl;
}

int main()
{
    while (1)
    {
        int choice;
        cout << "\nEnter choice, 1-Enter, 2-Display, 3-Pop, 4-Peep, 5-Exit: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter the data: ";
            cin >> data;
            push(data);
            break;
        case 2:
            display();
            break;
        case 3:
            pop();
            break;
        case 4:
            peep();
            break;
        case 5:
            return 0;
        }
    }
}
