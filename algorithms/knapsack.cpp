// 0/1 knapsack problem

#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int> wt, vector<int> val, int n) {
    if(n == 0 || W == 0) return 0; // base case
    if(wt[n-1] > W) return knapsack(W, wt, val, n-1); 
    return max(val[n-1] + knapsack(W-wt[n-1], wt, val, n-1), knapsack(W, wt, val, n-1));
}

int main() {
    vector<int> val;
    val.push_back(60);
    val.push_back(100);
    val.push_back(120);
    
    vector<int> wt;
    wt.push_back(10);
    wt.push_back(20);
    wt.push_back(30);
    
    int W = 30;
    int n = val.size();
    cout << "Total Value: "<<knapsack(W, wt, val, n) << endl; 
    return 0;
}
