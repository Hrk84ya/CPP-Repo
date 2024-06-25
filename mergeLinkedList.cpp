#include <iostream>
using namespace std;

// Define a structure for a singly linked list node
struct Node {
    int data;    // Data stored in the node
    Node* next;  // Pointer to the next node in the list
};

// Global pointers to heads of three lists
Node* head1 = NULL;
Node* head2 = NULL;
Node* head3 = NULL;  // Head of the merged list

// Function to insert a new node with given data at the beginning of a linked list
void insert(Node** head, int data) {
    // Create a new node
    Node* newNode = new Node();
    newNode->data = data;   // Assign data to the new node
    newNode->next = *head;  // Point new node's next to the current head
    *head = newNode;        // Move head to point to the new node
}

// Function to print a linked list starting from the given head
void print(Node* head){
    Node* temp = head;  // Temporary pointer to iterate through the list
    while(temp != NULL){
        cout << temp->data << " ";  // Print current node's data
        temp = temp->next;          // Move to the next node
    }
    cout << endl;  // Print a newline after the list is printed
}

// Function to merge two sorted linked lists into a third sorted linked list
void merge(Node* head1, Node* head2){
    Node* temp1 = head1;  // Temporary pointer for list 1
    Node* temp2 = head2;  // Temporary pointer for list 2

    // Iterate through both lists until either reaches the end
    while(temp1 != NULL && temp2 != NULL){
        // Compare the data of the current nodes
        if(temp1->data < temp2->data){
            // If data of temp1 is smaller, insert temp1's data into head3
            insert(&head3, temp1->data);
            temp1 = temp1->next;  // Move to the next node in list 1
        } else {
            // Otherwise, insert temp2's data into head3
            insert(&head3, temp2->data);
            temp2 = temp2->next;  // Move to the next node in list 2
        }
    }

    // If there are remaining nodes in list 1, insert them into head3
    while(temp1 != NULL){
        insert(&head3, temp1->data);
        temp1 = temp1->next;
    }

    // If there are remaining nodes in list 2, insert them into head3
    while(temp2 != NULL){
        insert(&head3, temp2->data);
        temp2 = temp2->next;
    }
}

// Main function where the program begins execution
int main() {
    // Insert elements into the first linked list (head1)
    insert(&head1, 7);
    insert(&head1, 5);
    insert(&head1, 3);
    insert(&head1, 1);

    // Insert elements into the second linked list (head2)
    insert(&head2, 8);
    insert(&head2, 6);
    insert(&head2, 4);
    insert(&head2, 2);

    // Print the first and second lists
    cout << "First List: ";
    print(head1);
    cout << "Second List: ";
    print(head2);

    // Merge the two lists and store the merged list in head3
    merge(head1, head2);

    // Print the merged list
    cout << "\nMerged List: ";
    print(head3);

    return 0;  // Return from main indicating successful execution
}
