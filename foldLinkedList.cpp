#include <iostream>
using namespace std;

// Define a structure for a singly linked list node
struct Node {
    char data;    // Data stored in the node (char type)
    Node* next;   // Pointer to the next node in the list
};

// Global pointer to the head of the linked list
Node* head = NULL;

// Function to insert a new node with given data at the beginning of the linked list
void insert(char data) { 
    // Create a new node
    Node* temp = new Node();
    temp->data = data;   // Assign data to the new node
    temp->next = head;   // Point new node's next to the current head
    head = temp;         // Move head to point to the new node
}

// Function to print the linked list starting from the head
void print() {
    Node* temp = head;  // Temporary pointer to iterate through the list
    while (temp != NULL) {
        cout << temp->data << " ";  // Print current node's data
        temp = temp->next;          // Move to the next node
    }
    cout << endl;  // Print a newline after the list is printed
}

// Function to fold the linked list
void fold() {
    // Find the middle of the linked list using slow and fast pointers
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         // Move slow pointer one step
        fast = fast->next->next;   // Move fast pointer two steps
    }

    // Reverse the second half of the linked list
    Node* prev = NULL;
    Node* curr = slow;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;   // Store next node
        curr->next = prev;   // Reverse current node's pointer
        prev = curr;         // Move pointers one position ahead
        curr = next;
    }

    // Merge the first half and reversed second half of the linked list
    Node* first = head;
    Node* second = prev;
    while (second->next != NULL) {
        Node* temp1 = first->next;   // Store next nodes
        Node* temp2 = second->next;
        first->next = second;        // Update pointers to fold
        second->next = temp1;
        first = temp1;               // Move to the next nodes
        second = temp2;
    }
}

// Main function where the program begins execution
int main() {
    // Insert elements into the linked list
    insert('g');
    insert('f');
    insert('e');
    insert('d');
    insert('c');
    insert('b');
    insert('a');

    // Print the original linked list
    cout << "Original Linked List: ";
    print();

    // Fold the linked list
    fold();

    // Print the folded linked list
    cout << "Folded Linked List: ";
    print();

    return 0;
}
