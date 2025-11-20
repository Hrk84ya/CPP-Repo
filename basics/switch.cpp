// Including the necessary header file for input-output operations
#include <iostream>
using namespace std;

int main() {
    int day; // Declaring a variable to store the day of the week

    // Prompting the user to enter the day
    cout << "Enter the day: ";
    cin >> day; // Reading the user input and storing it in the variable 'day'

    // Using a switch statement to perform actions based on the value of 'day'
    switch(day) {
        case 1:
            cout << "Today is Monday";
            break;
        case 2:
            cout << "Today is Tuesday"; 
            break;
        case 3:
            cout << "Today is Wednesday";
            break;
        case 4:
            cout << "Today is Thursday"; 
                        break;
        case 5:
            cout << "Today is Friday"; 
                        break;
        case 6:
            cout << "Today is Saturday"; 
                        break;
        case 7:
            cout << "Today is Sunday"; 
                        break;
        default:
            cout << "Invalid input"; 
    }

    return 0; 
}
