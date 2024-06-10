// Include the necessary library for input/output operations
#include <iostream>
using namespace std;

// Function to swap two integers   
void swap(int* a, int* b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

// Main function
int main() {
    int a=10;
    int b=20;

    cout<<"Value before swapping: ";
    cout<<a<<" "<<b<<endl;
    
    swap(&a,&b);
    cout<<"\n";
    
    cout<<"Value after swapping: ";
    cout<<a<<" "<<b<<endl;
    return 0;
}