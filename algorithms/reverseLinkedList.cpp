#include <iostream>
using namespace std;

// Node structure for the singly linked list
struct Node
{
    int data;
    Node *next;
};

// Global variable to point to the head of the linked list
Node *head = NULL;

// Function to insert a new node with data x at the beginning of the linked list
void insert(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
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
    cout << endl;
}

// Function to reverse the linked list
void reverse()
{
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer to the previous node
        prev = current;       // Move prev and current one step forward
        current = next;
    }
    head = prev; // Set the head to the last node (prev) after reversal
}

int main()
{
    // Insert elements into the linked list
    insert(8);
    insert(6);
    insert(4);
    insert(2);

    // Print the original linked list
    cout << "Original linked list: ";
    print();

    // Reverse the linked list
    reverse();

    // Print the reversed linked list
    cout << "Reversed linked list: ";
    print();

    return 0;
}
