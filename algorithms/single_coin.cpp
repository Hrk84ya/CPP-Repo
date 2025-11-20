#include <iostream>
#include <vector>
using namespace std;

// Function to find the number of combinations to achieve target sum
// with each coin being used at most once
int combi_sing_coin(vector<int> &arr, int idx, int tar) {
    // Base case: If target sum is achieved (tar == 0), return 1 way
    if (tar == 0) return 1;

    int ans = 0;
    // Iterate through the array from index 'idx' to end
    for (int i = idx; i < arr.size(); i++) {
        // If current coin can be used (tar - arr[i] >= 0),
        // recursively count combinations using this coin
        if (tar - arr[i] >= 0) {
            ans += combi_sing_coin(arr, i + 1, tar - arr[i]);
        }
    }
    return ans;
}

int main() {
    // Initialize vector of coins
    vector<int> coins;
    coins.push_back(2);
    coins.push_back(5);
    coins.push_back(3);
    coins.push_back(7);
    int target = 10;

    // Calculate the number of ways to achieve target sum
    int ways = combi_sing_coin(coins, 0, target);
    cout << "Number of ways to achieve target sum: " << ways << endl;

    return 0;
}
