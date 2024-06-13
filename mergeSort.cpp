// Include the necessary library for standard input and output and using vectors
#include <iostream> 
#include <vector> 
using namespace std;

// Function to merge two sorted vectors into one sorted vector
void merge(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int i = 0, j = 0, k = 0; 
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j]) // If the element of vector a is smaller
            c[k++] = a[i++]; // Copy it to vector c
        else // If the element of vector b is smaller
            c[k++] = b[j++]; // Copy it to vector c
    }
    // Copy the remaining elements of vector a to vector c
    while (i < a.size())
        c[k++] = a[i++];
    // Copy the remaining elements of vector b to vector c
    while (j < b.size())
        c[k++] = b[j++];
}

// Main function
int main()
{
    // Initialize vector a with some values
    vector<int> a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    a.push_back(40);
    a.push_back(50);

    // Initialize vector b with some values
    vector<int> b;
    b.push_back(15);
    b.push_back(25);
    b.push_back(35);
    b.push_back(45);
    b.push_back(55);

    // Initialize vector c with the combined size of vectors a and b
    vector<int> c(a.size() + b.size());
    // Merge vectors a and b into vector c
    merge(a, b, c);
    // Output the elements of vector c
    for (int i = 0; i < c.size(); i++)
        cout << c[i] << " ";
    return 0;
}
