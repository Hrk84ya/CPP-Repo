//find mid of linked list
//Never use the head pointer for traversal, if want to use then store its copy somewhere
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// Function to insert a new node at the end of the linked list
void insert(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

// Function to print all elements of the linked list
void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Function to find the middle node of the linked list
void findMid()
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;          // Move slow pointer by 1 step
        fast = fast->next->next;    // Move fast pointer by 2 steps
    }
    cout << "Mid of the linked list is: " << slow->data;
}

int main()
{
    // Insert elements into the linked list
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(9);
    insert(10);

    // Print the linked list
    print();
    cout << endl;

    // Find and print the middle node of the linked list
    findMid();

    return 0;
}
