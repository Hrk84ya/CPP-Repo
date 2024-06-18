#include <iostream>
#include <string>
using namespace std;

// Function to partition the array
// arr[]: array to be sorted
// low: starting index
// high: ending index
int partition(int arr[], int low, int high){
    // Select the pivot element (last element of the array)
    int pivot = arr[high];
    // Initialize the index of smaller element
    int i = low - 1;

    // Traverse through all elements of the array
    for(int j = low; j < high; j++){
        // If current element is smaller than or equal to pivot
        if(arr[j] < pivot){
            // Increment index of smaller element
            i++;
            // Swap arr[i] and arr[j]
            swap(arr[i], arr[j]);
        }
    }
    // Swap arr[i+1] and arr[high] (or pivot)
    swap(arr[i + 1], arr[high]);
    // Return the partitioning index
    return i + 1;
}

// Function to implement QuickSort algorithm
// arr[]: array to be sorted
// low: starting index
// high: ending index
void quickSort(int arr[], int low, int high){
    // Base case: when low is less than high
    if(low < high){
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);
        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    // Input array to be sorted
    int arr[] = {3, 2, 1, 4, 5, 12, 11, 10, 9};
    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);
    // Sort the array
    quickSort(arr, 0, n - 1);
    // Output the sorted array
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
