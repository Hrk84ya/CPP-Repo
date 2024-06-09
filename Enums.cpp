// Including the necessary header files for input-output operations and string manipulations
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Defining an enumeration named 'Level' to represent different levels
    enum Level {
        Low,
        Medium,
        High
    };
    
    // Declaring a variable 'myLevel' of type 'Level' and initializing it with the value 'Medium'
    Level myLevel = Medium;

    // Using a switch statement to perform actions based on the value of 'myLevel'
    switch(myLevel) {
        case Low:
            // If 'myLevel' is 'Low', print "Low level"
            cout << "Low level\n";
            break;
        case Medium:
            // If 'myLevel' is 'Medium', print "Medium level"
            cout << "Medium level\n";
            break;
        case High:
            // If 'myLevel' is 'High', print "High level"
            cout << "High level\n";
            break;
    }

    return 0;
}
