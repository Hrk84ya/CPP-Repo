#include <iostream>
using namespace std;

int main() {
    // Declare and initialize variables 'a' and 'b' with integer values.
    int a = 10;
    int b = 20;
    
    // Declare pointers 'p1' and 'p2' to integers and assign addresses of 'a' and 'b' respectively.
    int *p1 = &a;
    int *p2 = &b;
    
    // Declare pointers 'p3' and 'p4' to pointers to integers and assign addresses of 'p1' and 'p2' respectively.
    int** p3 = &p1;
    int** p4 = &p2;
    
    // Output the addresses stored in 'p1' and 'p2'.
    cout << "Addresses stored in p1 and p2: " << p1 << " " << p2 << endl;
    // Output the values pointed to by 'p1' and 'p2' (the values of 'a' and 'b').
    cout << "Values pointed to by p1 and p2: " << *p1 << " " << *p2 << endl;
    cout << "\n"; // Print a newline for clearer separation.
    
    // Output the addresses stored in 'p3' and 'p4'.
    cout << "Addresses stored in p3 and p4: " << p3 << " " << p4 << endl;
    // Output the values pointed to by the pointers stored in 'p3' and 'p4' (the values of 'a' and 'b').
    cout << "Values pointed to by *p3 and *p4: " << **p3 << " " << **p4 << endl;

    return 0;
}
