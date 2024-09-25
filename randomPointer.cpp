//Random Pointer without extra space
#include <iostream>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        Node *next = temp->next;
        temp->next = new Node(temp->data);
        temp->next->next = next;
        temp = next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->random != NULL)
        {
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }
    Node *newHead = head->next;
    Node *temp1 = head;
    Node *temp2 = newHead;
    while (temp1 != NULL)
    {
        temp1->next = temp2->next;
        if (temp2->next != NULL)
        {
            temp2->next = temp2->next->next;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return newHead;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next->next;
    head->next->next->next->next->random = head->next;
    Node *newHead = copyRandomList(head);
    Node *temp = newHead;
    while (temp != NULL)
    {
        cout <<"Data: "<< temp->data << " "<<"Random: ";
        if (temp->random != NULL)
        {
            cout << temp->random->data;
        }
        cout << endl;
        temp = temp->next;
    }
    return 0;
}