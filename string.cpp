// Including the necessary header files for input-output operations and string manipulations
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Declaring a string variable 'name' to store user's name
    string name;
    
    // Prompting the user to enter their name
    cout << "Enter your name: ";
    cin >> name; // Reading the user input and storing it in the variable 'name'
    
    // Greeting the user with their name
    cout << "Hello, " << name << "!\n";

    // Declaring and initializing two string variables 'firstName' and 'lastName'
    string firstName = "Harsh ";
    string lastName = "Kumar";

    // Concatenating 'firstName' and 'lastName' to form 'fullName'
    string fullName = firstName.append(lastName);
    cout << fullName << "\n";

    // Using the length function to get the length of the string 'fullName'
    cout << "The length of fullName is: " << fullName.length() << "\n";

    // Using the at function to access the character at index 1 in the string 'fullName'
    cout << fullName.at(1) << "\n";

    // Clearing the input buffer
    cin.ignore();

    // Declaring a string variable 'favCharacter' to store user's favorite character
    string favCharacter;
    
    // Prompting the user to enter their favorite character
    cout << "Enter your favorite character: ";
    
    // Reading a line of input (allowing spaces) and storing it in the variable 'favCharacter'
    getline(cin, favCharacter);
    
    // Displaying the user's favorite character
    cout << "Your favorite character is: " << favCharacter;

    return 0;
}
