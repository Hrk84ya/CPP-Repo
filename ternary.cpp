// Including the necessary header files for input-output operations and string manipulations
#include <iostream>
#include <string>
using namespace std;

int main() {
    int age; // Declaring a variable to store the age

    // Prompting the user to enter their age
    cout << "Enter your age: ";
    cin >> age; // Reading the user input and storing it in the variable 'age'

    // Using the ternary operator to determine if the age is greater than 18
    // If age > 18, assign "Adult" to the string variable 'result', otherwise assign "Not Adult"
    string result = (age > 18) ? "Adult" : "Not Adult";

    // Outputting the result
    cout << result; // Outputting whether the person is an adult or not

    return 0; 
}
