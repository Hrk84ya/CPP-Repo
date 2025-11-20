// Including the necessary header file for input-output operations
#include <iostream>
using namespace std;

int main() {
    int num1, num2; // Declaring variables to store the entered numbers

    // Prompting the user to enter the first number
    cout << "Enter a number: ";
    cin >> num1; // Reading the user input and storing it in 'num1'

    // Prompting the user to enter the second number
    cout << "Enter another number: ";
    cin >> num2; // Reading the user input and storing it in 'num2'

    // Performing arithmetic operations
    int sum = num1 + num2;    // Addition
    int diff = num1 - num2;   // Subtraction
    int prod = num1 * num2;   // Multiplication
    int quot = num1 / num2;   // Integer division

    // Outputting the results of the arithmetic operations
    cout << "Sum of " << num1 << " and " << num2 << " is: " << sum << "\n";
    cout << "Difference of " << num1 << " and " << num2 << " is: " << diff << "\n";
    cout << "Product of " << num1 << " and " << num2 << " is: " << prod << "\n";
    cout << "Quotient of " << num1 << " and " << num2 << " is: " << quot;

    return 0;
}
