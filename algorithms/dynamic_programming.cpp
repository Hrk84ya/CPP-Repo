#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// Fibonacci with memoization
int fibonacci_memo(int n, std::vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    
    memo[n] = fibonacci_memo(n-1, memo) + fibonacci_memo(n-2, memo);
    return memo[n];
}

// Fibonacci with tabulation (bottom-up)
int fibonacci_tab(int n) {
    if (n <= 1) return n;
    
    std::vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

// Longest Common Subsequence
int lcs(const std::string& s1, const std::string& s2) {
    int m = s1.length();
    int n = s2.length();
    
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}

// 0/1 Knapsack Problem
int knapsack_01(const std::vector<int>& weights, const std::vector<int>& values, int capacity) {
    int n = weights.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i-1] <= w) {
                dp[i][w] = std::max(
                    values[i-1] + dp[i-1][w - weights[i-1]],  // Include item
                    dp[i-1][w]  // Exclude item
                );
            } else {
                dp[i][w] = dp[i-1][w];  // Can't include item
            }
        }
    }
    
    return dp[n][capacity];
}

// Coin Change Problem (minimum coins)
int coin_change(const std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

// Longest Increasing Subsequence
int lis(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> dp(n, 1);
    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }
    
    return *std::max_element(dp.begin(), dp.end());
}

// Edit Distance (Levenshtein Distance)
int edit_distance(const std::string& s1, const std::string& s2) {
    int m = s1.length();
    int n = s2.length();
    
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
    
    // Initialize base cases
    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int j = 0; j <= n; ++j) dp[0][j] = j;
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];  // No operation needed
            } else {
                dp[i][j] = 1 + std::min({
                    dp[i-1][j],     // Delete
                    dp[i][j-1],     // Insert
                    dp[i-1][j-1]    // Replace
                });
            }
        }
    }
    
    return dp[m][n];
}

// Maximum Subarray Sum (Kadane's Algorithm)
int max_subarray_sum(const std::vector<int>& arr) {
    int max_ending_here = arr[0];
    int max_so_far = arr[0];
    
    for (size_t i = 1; i < arr.size(); ++i) {
        max_ending_here = std::max(arr[i], max_ending_here + arr[i]);
        max_so_far = std::max(max_so_far, max_ending_here);
    }
    
    return max_so_far;
}

int main() {
    std::cout << "=== Dynamic Programming Examples ===\n\n";
    
    // Fibonacci
    std::cout << "1. Fibonacci Numbers:\n";
    int n = 10;
    std::vector<int> memo(n + 1, -1);
    std::cout << "Fibonacci(" << n << ") with memoization: " << fibonacci_memo(n, memo) << "\n";
    std::cout << "Fibonacci(" << n << ") with tabulation: " << fibonacci_tab(n) << "\n\n";
    
    // Longest Common Subsequence
    std::cout << "2. Longest Common Subsequence:\n";
    std::string s1 = "ABCDGH";
    std::string s2 = "AEDFHR";
    std::cout << "LCS of \"" << s1 << "\" and \"" << s2 << "\": " << lcs(s1, s2) << "\n\n";
    
    // 0/1 Knapsack
    std::cout << "3. 0/1 Knapsack Problem:\n";
    std::vector<int> weights = {10, 20, 30};
    std::vector<int> values = {60, 100, 120};
    int capacity = 50;
    std::cout << "Maximum value with capacity " << capacity << ": " 
              << knapsack_01(weights, values, capacity) << "\n\n";
    
    // Coin Change
    std::cout << "4. Coin Change Problem:\n";
    std::vector<int> coins = {1, 3, 4};
    int amount = 6;
    std::cout << "Minimum coins needed for amount " << amount << ": " 
              << coin_change(coins, amount) << "\n\n";
    
    // Longest Increasing Subsequence
    std::cout << "5. Longest Increasing Subsequence:\n";
    std::vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << "LIS length: " << lis(arr) << "\n\n";
    
    // Edit Distance
    std::cout << "6. Edit Distance:\n";
    std::string str1 = "sunday";
    std::string str2 = "saturday";
    std::cout << "Edit distance between \"" << str1 << "\" and \"" << str2 << "\": " 
              << edit_distance(str1, str2) << "\n\n";
    
    // Maximum Subarray Sum
    std::cout << "7. Maximum Subarray Sum (Kadane's Algorithm):\n";
    std::vector<int> subarray = {-2, -3, 4, -1, -2, 1, 5, -3};
    std::cout << "Maximum subarray sum: " << max_subarray_sum(subarray) << "\n";
    
    return 0;
}