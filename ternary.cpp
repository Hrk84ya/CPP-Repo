//Using the ternary operator to ease out the condition

#include <iostream>
#include <string>
using namespace std;

int main(){
    int age;
    cout << "Enter your age: ";
    cin >> age;
    string result=(age>18)?"Adult":"Not Adult";
    cout << result;
    return 0;
}