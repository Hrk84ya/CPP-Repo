// Including the necessary header file for input-output operations
#include <iostream>
using namespace std;

int main() {
    int age; // Declaring a variable to store the age

    // Prompting the user to enter their age
    cout << "Enter your age: ";
    cin >> age; // Reading the user input and storing it in the variable 'age'

    // Using conditional statements to determine the life stage based on the age
    if (age < 13) {
        // If the age is less than 13, the person is considered a child
        cout << "You are a child";
    } else if (age < 18) {
        // If the age is between 13 and 17 (inclusive), the person is considered a teenager
        cout << "You are a teenager";
    } else {
        // If the age is 18 or more, the person is considered an adult
        cout << "You are an adult";
    }

    return 0;
}
