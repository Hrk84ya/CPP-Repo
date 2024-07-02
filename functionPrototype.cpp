//FUNCTION PROTOTYPE
#include<iostream>
using namespace std;

int square(int x);

int main(){
    cout<<"Enter a number: ";
    int x;
    cin>>x;
    cout<<"Square of "<<x<<" is: "<<square(x)<<endl;
    return 0;
}

int square(int x){
    return x*x;
}