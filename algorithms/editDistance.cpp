//Edit distance problem

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int min(int a, int b, int c) {
    return min(min(a, b), c);
}

int editDistance(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string str1 = "saturday";
    string str2 = "sunday";
    cout << editDistance(str1, str2) << endl;
    return 0;
}