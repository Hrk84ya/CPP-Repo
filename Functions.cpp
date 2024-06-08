#include <iostream>
#include <string>
using namespace std;

void greet(string fname,int age){
    cout<<"Hello "<<fname<<"! You're "<<age<<" years old\n";
}

void country(string country="India"){
    cout<<"You're from "<<country;
}

int main(){
    greet("Harsh",19);
    country("India");
    cout<<"\n";
    greet("Jane",20);
    country();
    return 0;
}