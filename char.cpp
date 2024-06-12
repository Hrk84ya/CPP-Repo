//create a character array and print the address of each element
#include <iostream>
using namespace std;

int main() {
    char arr[] = "Harsh Kumar";
    
    for (int i = 0; i < 12; i++) {
        cout << "Address of arr[" << i << "]: " << (void*)&arr[i] << endl;
    }
    return 0;
}
