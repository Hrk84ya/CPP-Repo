// Including the necessary header files for input-output operations and string manipulations
#include <iostream>
#include <string>
using namespace std;

// Function to greet a person with their name and age
void greet(string fname, int age) {
    cout << "Hello " << fname << "! You're " << age << " years old\n";
}

// Function to output the country a person is from, with a default value of "India"
void country(string country = "India") {
    cout << "You're from " << country;
}

int main() {
    // Calling the greet function with name "Harsh" and age 19
    greet("Harsh", 19);
    // Calling the country function with the specified country "India"
    country("India");
    cout << "\n"; // Printing a newline for better readability

    // Calling the greet function with name "Jane" and age 20
    greet("Jane", 20);
    // Calling the country function with the default country "India"
    country();

    return 0;
}
