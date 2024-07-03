#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n, int i = 0, int j = 0) {
    if(i >= m || j >= n) return 0;                                    // reached out of bounds - invalid
    if(i == m-1 && j == n-1) return 1;                                // reached the destination - valid solution
    return uniquePaths(m, n, i+1, j) + uniquePaths(m, n, i, j+1);     // try both down and right
};

int main() {
    cout << uniquePaths(3, 7) << endl; // 28
    return 0;
}
