//Using the condition statements
#include <iostream>
using namespace std;

int main(){
    int age;
    cout << "Enter your age: ";
    cin >> age;

    if (age<13){
        cout<<"You are a child";
    }else if(age<18){
        cout<<"You are a teenager";
    }else{
        cout<<"You are an adult";
    }
    return 0;
}