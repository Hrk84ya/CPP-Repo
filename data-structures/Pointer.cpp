// Including the necessary header files for input-output operations and string manipulations
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Initializing a string variable with the value "Pizza"
    string food = "Pizza";

    // Declaring a pointer to a string and assigning it the address of the variable 'food'
    string *ptr = &food;

    // Output the value of the variable 'food'
    cout << food << "\n"; // Output: Pizza

    // Output the memory address stored in the pointer 'ptr' (address of the variable 'food')
    cout << ptr << "\n"; // Output: address of the variable

    // Output the value pointed to by the pointer 'ptr' (content of the variable 'food')
    cout << *ptr << "\n"; // Output: Pizza

    // Changing the content of the variable 'food' using the pointer 'ptr'
    *ptr = "Noodles";

    // Output the new value pointed to by the pointer 'ptr' (updated content of the variable 'food')
    cout << *ptr << "\n"; // Output: Noodles

    return 0;
}
