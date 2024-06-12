//Selection sort
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    // Iterate through the array from the beginning to the second-to-last element.
    for (int i = 0; i < n - 1; i++) {
        // Assume the current element is the minimum.
        int minIndex = i;
        
        // Iterate through the unsorted portion of the array.
        for (int j = i + 1; j < n; j++) {
            // If we find an element smaller than the current minimum, update the minimum index.
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the current element with the minimum element found.
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    selectionSort(arr, n);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
