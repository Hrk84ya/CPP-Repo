//Given a linked list, return k node from the end
// 1->2->3->4->5->6->7->8->9->10
// k = 3
// output = 8

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *kthNode(Node *head, int k)
{
    Node *slow = head;
    Node *fast = head;
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->next->next->next = new Node(10);
    Node *res = kthNode(head, 3);
    cout <<"Element is: "<< res->data;
    return 0;
}

