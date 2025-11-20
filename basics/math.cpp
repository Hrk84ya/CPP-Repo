// Including the necessary header files for input-output operations and mathematical functions
#include <iostream>
#include <cmath>
using namespace std;

// Function to handle square root calculation
double calculateSquareRoot(double num) {
    if (num >= 0) {
        return sqrt(num);
    } else {
        cout << "Cannot calculate square root of a negative number." << endl;
        return -1; // Returning -1 to indicate error
    }
}

// Function to handle rounding to the nearest integer
int roundToNearestInt(double num) {
    return round(num);
}

// Function to find maximum of two numbers
int findMaximum(int a, int b) {
    return max(a, b);
}

int main(){
    double input;
    cout << "Enter a number: ";
    cin >> input;

    // Calculate and display square root
    double sqrtResult = calculateSquareRoot(input);
    if (sqrtResult != -1) {
        cout << "Square root: " << sqrtResult << endl;
    }

    // Calculate and display rounded value
    cout << "Rounded value: " << roundToNearestInt(input) << endl;

    // Find and display maximum with another number
    int otherNumber;
    cout << "Enter another number: ";
    cin >> otherNumber;
    cout << "Maximum: " << findMaximum(roundToNearestInt(input), otherNumber) << endl;

    return 0;
}
