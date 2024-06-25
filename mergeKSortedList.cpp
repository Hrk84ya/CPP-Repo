#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> q;
    for (ListNode* l : lists) {
        if (l) {
            q.push(l);
        }
    }
    if (q.empty()) {
        return NULL;
    }
    ListNode* result = q.top();
    q.pop();
    if (result->next) {
        q.push(result->next);
    }
    ListNode* tail = result;
    while (!q.empty()) {
        tail->next = q.top();
        q.pop();
        tail = tail->next;
        if (tail->next) {
            q.push(tail->next);
        }
    }
    return result;
}

int main() {
    vector<ListNode*> lists;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    lists.push_back(l1);
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    lists.push_back(l2);
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);
    lists.push_back(l3);
    ListNode* result = mergeKLists(lists);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}

