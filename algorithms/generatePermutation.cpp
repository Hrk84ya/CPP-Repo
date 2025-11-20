#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to generate permutations of the vector 'arr' from index 'start' to 'end'
void generatePermutations(vector<int> &arr, int start, int end) {
    // Base case: if start equals end, we have generated a permutation
    if(start == end) {
        // Print the permutation
        for(int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        // Recursive case: generate permutations by swapping elements
        for(int i = start; i <= end; i++) {
            // Swap elements at indices start and i
            swap(arr[start], arr[i]);
            // Recursively generate permutations for the remaining elements
            generatePermutations(arr, start + 1, end);
            // Backtrack: restore the original order of elements
            swap(arr[start], arr[i]);
        }
    }
}

int main() {
    // Read input size n
    int n;
    cin >> n;
    
    // Read n integers into vector arr
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    // Generate permutations of the vector arr from index 0 to n-1
    generatePermutations(arr, 0, n - 1);
    
    return 0;
}
