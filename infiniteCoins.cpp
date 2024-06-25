#include <iostream>
#include <vector>
using namespace std;

// Function to find the number of combinations to achieve 'tar' using coins from 'arr' starting from index 'idx'
int combi_inf_coin(vector<int> &arr, int idx, int tar){
    // Base case: if 'tar' is reduced to 0, we have found a valid combination
    if (tar == 0) {
        return 1;  // Return 1 to signify a valid combination found
    }

    int ans = 0;  // Variable to store the number of valid combinations

    // Iterate through the coins starting from index 'idx'
    for (int i = idx; i < arr.size(); i++){
        // If current coin can be used (i.e., tar - arr[i] >= 0), recursively find combinations
        if (tar - arr[i] >= 0){
            ans += combi_inf_coin(arr, i, tar - arr[i]);  // Recursively call with reduced target
        }
    }
    return ans;  // Return the total number of combinations
}

int main(){
    vector<int> coins;
    coins.push_back(2);
    coins.push_back(3);
    coins.push_back(5);
    coins.push_back(7);
    int target = 10;

    // Find the number of ways to achieve target sum using coins from 'coins' starting from index 0
    int ways = combi_inf_coin(coins, 0, target);

    // Output the result
    cout << "Number of ways to achieve target sum: " << ways << endl;

    return 0; 
}
