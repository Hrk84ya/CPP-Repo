#include <iostream> 
#include <string>    
using namespace std; 

// Define a base class GrandFather
class GrandFather {
    public:
        // A method to print "Grandfather"
        void grandFather() {
            cout << "Grandfather\n";
        }
};

// Define a derived class Father inheriting from GrandFather
class Father : public GrandFather {
    public:
        // A method to print "Father"
        void father() {
            cout << "Father\n";
        }
};

// Define a derived class Son inheriting from Father
class Son : public Father {
    public:
        // A method to print "Son"
        void son() {
            cout << "Son\n";
        }
};

int main() {
    Son s; // Create an instance of Son

    // Call the methods from GrandFather, Father, and Son classes
    s.grandFather(); // Calls the GrandFather class method
    s.father();      // Calls the Father class method
    s.son();         // Calls the Son class method

    return 0;
}
