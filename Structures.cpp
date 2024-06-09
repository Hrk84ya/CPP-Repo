// Including the necessary header files for input-output operations and string manipulations
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Defining a structure to store information about a person
    struct {
        int myAge;        // Member to store age
        string myName;    // Member to store name
    } myStruct;           // Declaring an instance of the structure

    // Prompting the user to enter their age
    cout << "Enter your age: ";
    cin >> myStruct.myAge; // Reading the user input and storing it in the 'myAge' member of the structure

    // Clearing the input buffer
    cin.ignore();

    // Prompting the user to enter their name
    cout << "Enter your name: ";
    // Reading a line of input (allowing spaces) and storing it in the 'myName' member of the structure
    getline(cin, myStruct.myName);

    // Outputting the user's name and age
    cout << "My name is " << myStruct.myName << " and I am " << myStruct.myAge << " years old.\n";

    return 0;
}
