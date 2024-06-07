//Using the cin function to take input from the user

#include <iostream>
using namespace std;

int main(){
    int num1,num2;
    cout << "Enter a number: ";
    cin >> num1;

    cout << "Enter another number: ";
    cin >> num2;

    int sum=num1+num2;
    int diff=num1-num2;
    int prod=num1*num2;
    int quot=num1/num2;

    cout << "Sum of "<<num1<<" and "<<num2<<" is: "<<sum << "\n";
    cout << "Difference of "<<num1<<" and "<<num2<<" is: "<<diff << "\n";
    cout << "Product of "<<num1<<" and "<<num2<<" is: "<<prod<<"\n";
    cout << "Quotient of "<<num1<<" and "<<num2<<" is: "<<quot;
}