//Trick to check if an integer is power of 2
#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a value: ";
    cin>>n;
    bool power_of_2 = n && !(n & (n - 1));

    if(power_of_2==true){
        cout<<"Power of 2\n";
    }else{
        cout<<"Not a power of 2\n";
    }

    return 0;
}