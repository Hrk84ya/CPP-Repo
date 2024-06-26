//Clone a Linked List with next and Random Pointer
#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;
    Node(int x) {
        data = x;
        next = random = NULL;
    }
};

Node* clone(Node* head) {
    unordered_map<Node*, Node*> mp;
    Node* curr = head;
    while (curr != NULL) {
        mp[curr] = new Node(curr->data);
        curr = curr->next;
    }
    curr = head;
    while (curr != NULL) {
        mp[curr]->next = mp[curr->next];
        mp[curr]->random = mp[curr->random];
        curr = curr->next;
    }
    return mp[head];
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(20);
    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next->next->next;
    Node* cloned = clone(head);
    Node* curr = cloned;
    while (curr != NULL) {
        cout << "Data = " << curr->data << ", Random = " << curr->random->data << endl;
        curr = curr->next;
    }
    return 0;
}

