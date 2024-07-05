// longest palindromic subsequence

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestPalindromeSubseq(string s)
{
    int n = s.size();
    vector<vector<int> > dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (s.empty())
    {
        cout << "Error: Input string is empty." << endl;
        return 1;
    }

    // Check if the input string contains non-alphabetic characters
    for (char c : s)
    {
        if (!isalpha(c))
        {
            cout << "Error: Input string contains non-alphabetic characters." << endl;
            return 1;
        }
    }

    cout << "Length of the longest palindromic subsequence: " << longestPalindromeSubseq(s) << endl;
    return 0;
}