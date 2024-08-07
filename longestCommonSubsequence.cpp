// Longest common subsequence

#include <iostream>
using namespace std;

int lcs(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main()
{
    string s1 = "Harsh";
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    string s2 = "Utkarsh";
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    cout << lcs(s1, s2) << endl;
    return 0;
}
