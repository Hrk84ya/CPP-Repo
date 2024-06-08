//Utilizing the string library

#include <iostream>
#include <string>
using namespace std;

int main(){
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello, " << name << "!\n";

    string firstName = "Harsh ";
    string lastName = "Kumar";

    string fullName = firstName.append(lastName);
    cout << fullName<<"\n";

    //using the length function to get the length of a string
    cout << "The length of fullName is: "<<fullName.length()<<"\n";

    //using the at function to access character of a string
    cout << fullName.at(1)<<"\n";

    //Clear the input buffer
    cin.ignore();

    //Taking an input line
    string favCharacter;
    cout << "Enter your favorite character: ";
    getline(cin, favCharacter);
    cout << "Your favorite character is: "<<favCharacter;

    return 0;
}