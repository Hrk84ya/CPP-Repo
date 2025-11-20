// The painter's partition problem
// This problem aims to minimize the maximum number of pages a painter has to paint, given the constraint that each section can only be painted by one painter, and each painter can only paint contiguous sections.

#include <climits> // Library for using INT_MAX and INT_MIN
#include <iostream> // Library for standard input and output
using namespace std;

// Function to calculate the sum of elements in an array within a given range
int sum(int arr[], int from, int to)
{
    int total = 0;
    for (int i = from; i <= to; i++) // Loop through the array from 'from' index to 'to' index
        total += arr[i]; // Summing up the elements within the range
    return total; // Return the sum
}

// Function to calculate the minimum of the maximum sum required to paint sections
// Parameters:
// arr[]: Array representing the sections to be painted
// n: Total number of sections
// k: Total number of painters
int partition(int arr[], int n, int k)
{
    // Base cases
    if (k == 1) // If only one painter is available
        return sum(arr, 0, n - 1); // Paint all the sections
    if (n == 1) // If only one section is available
        return arr[0]; // Assign that section to the painter

    int best = INT_MAX; // Initialize 'best' with the maximum possible integer value
    
    // Iterate over all possible partitions of sections
    for (int i = 1; i <= n; i++)
        // Calculate the minimum of the maximum sum required by:
        // 1. Splitting the remaining sections into k-1 painters and calculating the maximum sum for the current partition
        // 2. Calculating the sum for the current partition
        best = min(best, max(partition(arr, i, k - 1), sum(arr, i, n - 1)));

    return best; // Return the minimum of the maximum sums
}

// Main function
int main()
{
    int arr[] = { 10, 20, 60, 50, 30, 40 }; // Array representing the number of pages in each section
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; // Total number of painters
    cout << partition(arr, n, k) << endl; 
    return 0; 
}
