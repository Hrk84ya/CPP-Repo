#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int kthSmallest(vector<int> &arr, int k) {
    priority_queue<int> pq;
    for (int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    return pq.top();
}

vector<int> kSmallest(vector<int> &arr, int k) {
    priority_queue<int> pq;
    vector<int> res;
    for (int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    while (!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}


int main() {
    vector<int> arr;
    arr.push_back(7);
    arr.push_back(10);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(20);
    arr.push_back(15);
    arr.push_back(25);
    int k = 3;
    cout << k << "th smallest number is: " << kthSmallest(arr, k) << endl;
    vector<int> res = kSmallest(arr, k);
    cout << k << " smallest numbers are: ";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}