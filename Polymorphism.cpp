// Including the necessary header files for input-output operations and string manipulations
#include <iostream>  
#include <string>    
using namespace std; 

// Define a base class Animal
class Animal {
    public:
        // A method to produce a generic animal sound
        void animalSound() {
            cout << "This animal produces sound!\n";
        }
};

// Define a derived class Dog inheriting from Animal
class Dog : public Animal {
    public:
        // Override the animalSound method to specify the sound a dog makes
        void animalSound() {
            cout << "Dog barks\n";
        }
};

// Define a derived class Cat inheriting from Animal
class Cat : public Animal {
    public:
        // Override the animalSound method to specify the sound a cat makes
        void animalSound() {
            cout << "Cat meows\n";
        }
};

int main() {
    Animal a; // Create an instance of Animal
    Dog d;    // Create an instance of Dog
    Cat c;    // Create an instance of Cat

    // Call the animalSound method on each instance
    a.animalSound(); // Calls the Animal class method
    d.animalSound(); // Calls the overridden Dog class method
    c.animalSound(); // Calls the overridden Cat class method

    return 0;
}
