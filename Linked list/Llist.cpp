#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} * head;

void createNode(int n)
{

    int data;
    cout << "Enter data of 1st node: ";
    cin >> data;

    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = data;
    head->next = NULL;

    struct Node *temp = head;

    for (int i = 0; i < n - 1; i++)
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

        cout << "Enter data of " << i + 2 << "th node: ";
        cin >> data;
        newnode->data = data;
        newnode->next = NULL;

        temp->next = newnode;
        temp = temp->next;
    }
}

void travese()
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    int n;
    n = 5;
    createNode(n);
    travese();
}