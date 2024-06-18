#include <iostream>
#include <vector>
using namespace std;

int sing_coin(vector<int> &arr, int idx, int tar) {
    // using no coins since target is 0
    if (tar == 0) {
        return 1;
    }

    // If no coins left or target is negative, no way to achieve the target
    if (idx == arr.size() || tar < 0) {
        return 0;
    }

    // Recursive case: Include the current coin `arr[idx]` or exclude it
    int includeCurrent = sing_coin(arr, idx + 1, tar - arr[idx]);
    int excludeCurrent = sing_coin(arr, idx + 1, tar);

    // Return the sum of ways by including or excluding the current coin
    return includeCurrent + excludeCurrent;
}

int main() {
    vector<int> coins; // Example coin denominations
    coins.push_back(2);
    coins.push_back(2);
    coins.push_back(4);
    coins.push_back(3);
    coins.push_back(5);
    coins.push_back(7);

    int target = 10; // Example target sum

    int ways = sing_coin(coins, 0, target);
    cout << "Number of ways to achieve target sum: " << ways << endl;

    return 0;
}
