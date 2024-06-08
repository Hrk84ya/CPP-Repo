#include <iostream>
#include <string>
using namespace std;

int main(){
    string food="Pizza";
    string *ptr=&food;

    cout <<food<<"\n"; //output: Pizza
    cout <<ptr<<"\n"; //output: address of the variable
    cout <<*ptr<<"\n"; //output: content of the variable

    *ptr="Noodles"; //changing the content of the variable using pointer
    cout <<*ptr<<"\n";

    return 0;
}