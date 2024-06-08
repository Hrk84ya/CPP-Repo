#include <iostream>
#include <string>
using namespace std;

int main(){
    struct{
        int myAge;
        string myName;
    }myStruct;
    cout << "Enter your age: ";
    cin >> myStruct.myAge;

    //To clear the input buffer
    cin.ignore();
    
    cout << "Enter your name: ";
    getline(cin,myStruct.myName);
    cout<<"My name is "<<myStruct.myName<<" and I am "<<myStruct.myAge<<" years old.\n";
    return 0;
}